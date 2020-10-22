# -*- coding: utf-8 -*-
"""
Created on Fri Jun 26 12:22:18 2020

@author: sutar
"""

from collections import Counter
import numpy as np
import pandas as pd
import sys

data = pd.read_csv('spam.csv')

data["v3"] = data.v1.map({'ham':0, 'spam':1})

#print(data.count())  - 5572

training_data = data.sample(frac=0.8,random_state=200)
test_data = data.drop(training_data.index)

spam_counts = Counter()
ham_counts = Counter()
total_counts = Counter()
spam_ham_ratios = Counter()

for i,row in enumerate(training_data.values):
    if(row[2]==0):
        for word in row[1].split(" "):
            ham_counts[word] += 1
            total_counts[word] +=1
    else:
        for word in  row[1].split(" "):
            spam_counts[word] += 1
            total_counts[word] +=1
            
for word,count in list(total_counts.most_common()):
    if(count > 100):
        spam_ham_ratio = spam_counts[word] / float(ham_counts[word]+1)
        spam_ham_ratios[word] = spam_ham_ratio
        
for word,ratio in spam_ham_ratios.most_common():
    if(ratio > 1):
        spam_ham_ratios[word] = np.log(ratio)
    else:
        spam_ham_ratios[word] = -np.log((1 / (ratio+0.01)))

for i,row in enumerate(test_data.values):
        for word in row[1].split(" "):
            total_counts[word] +=1
        
vocab = set(total_counts.keys())
word_column_dict = {}
for i, word in enumerate(vocab):
    word_column_dict[word] = i
vocab_vector = np.zeros((1, len(vocab)))

class SpamClassificationNeuralNetwork(object):
    def __init__(self, training_data, test_data, num_hidden_nodes = 10, num_epochs = 10, learning_rate = 0.1):
        # set our random number generator 
        np.random.seed(1)
        # pre-process data
        self.pre_process_data(training_data,test_data)
        self.num_features = len(self.vocab)
        self.vocab_vector = np.zeros((1, len(self.vocab)))
        self.num_input_nodes = self.num_features
        self.num_hidden_nodes = num_hidden_nodes
        self.num_epochs = num_epochs
        self.num_output_nodes = 1
        self.learning_rate = learning_rate

        # Initialize weights
        self.weights_i_h = np.random.randn(self.num_input_nodes, self.num_hidden_nodes)
        self.weights_h_o = np.random.randn(self.num_hidden_nodes, self.num_output_nodes)
        
    def forward_backward_propagate(self, text, label):
        #Forward pass
        # Input Layer
        self.update_input_layer(text)
        # Hidden layer
        hidden_layer = self.vocab_vector.dot(self.weights_i_h)
        # Output layer
        output_layer = self.sigmoid(hidden_layer.dot(self.weights_h_o))
        
        #Backward pass
        # Output error
        output_layer_error = output_layer - label 
        output_layer_delta = output_layer_error * self.sigmoid_derivative(output_layer)

        #hidden layer gradients - no nonlinearity so it's the same as the error
        hidden_layer_delta = output_layer_error 

        #update the weights - with grdient descent
        self.weights_h_o -= hidden_layer.T.dot(output_layer_delta) * self.learning_rate 
        self.weights_i_h -= self.vocab_vector.T.dot(hidden_layer_delta) * self.learning_rate 
        
        if(np.abs(output_layer_error) < 0.5):
                self.correct_so_far += 1
                
    def test_forward_backward_propagate(self, text, label):
        #Forward pass
        # Input Layer
        self.update_input_layer(text)
        # Hidden layer
        hidden_layer = self.vocab_vector.dot(self.weights_i_h)
        # Output layer
        output_layer = self.sigmoid(hidden_layer.dot(self.weights_h_o))
        
        output_layer_error = output_layer - label
        
        if(np.abs(output_layer_error) < 0.5):
                self.correct_so_far += 1

    def sigmoid(self,x):
        return 1 / (1 + np.exp(-x))
    
    
    def sigmoid_derivative(self,x):
        return x * (1 - x)

        
    def train(self):
        for epoch in range(self.num_epochs):
            self.correct_so_far = 0
            for i,row in enumerate(training_data.values):
                # Forward and Back Propagation
                self.forward_backward_propagate(row[1],row[2])
                sys.stdout.write("\rEpoch: "+ str(epoch)
                                 +" Progress: " + str(100 * i/float(len(training_data)))[:4]
                                 + " #Correctly Classified: " + str(self.correct_so_far) 
                                 + " #Trained: " + str(i+1) 
                                 + " Training Accuracy: " + str(self.correct_so_far * 100 / float(i+1))[:4] + "%")
            print("")
    
    def test(self):
        self.correct_so_far = 0
        for i,row in enumerate(test_data.values):
            # Forward Propagation
            self.test_forward_backward_propagate(row[1],row[2])
            sys.stdout.write("\r Test-Data - Progress: " + str(100 * i/float(len(test_data)))[:4]
                                 + " #Correctly Classified: " + str(self.correct_so_far) 
                                 + " Accuracy: " + str(self.correct_so_far * 100 / float(i+1))[:4] + "%")
        print("")
        
    def pre_process_data(self, training_data,test_data):
        vocab = set()
        for review in training_data["v2"]:
            for word in review.split(" "):
                vocab.add(word)
        self.vocab = list(vocab)
        self.word_to_column = {}
        for i, word in enumerate(self.vocab):
            self.word_to_column[word] = i
        for review in test_data["v2"]:
            for word in review.split(" "):
                vocab.add(word)
        self.vocab = list(vocab)
        self.word_to_column = {}
        for i, word in enumerate(self.vocab):
            self.word_to_column[word] = i
            
    def update_input_layer(self, text):
        global vocab_vector
        #reset the vector to be all 0s
        self.vocab_vector *= 0
        for word in text.split(" "):
            self.vocab_vector[0][word_column_dict[word]] += 1

neuralnetwork = SpamClassificationNeuralNetwork(training_data,test_data,num_epochs = 10, learning_rate=0.01)
neuralnetwork.train()
print("")
neuralnetwork.test()