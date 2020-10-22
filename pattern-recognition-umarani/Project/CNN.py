import numpy 
numpy.random.seed(0)
import tensorflow
tensorflow.random.set_seed(0)

#CNN import libraries
from pathlib import Path
from keras.layers import Dense
from keras.layers import Convolution2D
from keras.layers import Flatten
from keras.layers import MaxPooling2D
from keras.layers import Activation,Dropout
from keras.models import Sequential
import os
import numpy as np
import matplotlib.pyplot as plt
img_width,img_height = (200,200)
from keras.preprocessing.image import ImageDataGenerator
#model initialize
classifier = Sequential()
#add convolutional layer32, 3x3 filters, 2 stride relu activation
classifier.add(Convolution2D(32,3,2,input_shape=(200,200,3),activation = "relu"))
#add maxpooling layer of poilsize 2x2
classifier.add(MaxPooling2D(pool_size=(2,2)))
#add convolutional layer32, 3x3 filters, 2 stride relu activation
classifier.add(Convolution2D(32,3,2,input_shape=(200,200,3),activation = "relu"))
#add maxpooling layer of poilsize 2x2
classifier.add(MaxPooling2D(pool_size=(2,2)))
#add convolutional layer32, 3x3 filters, 2 stride relu activation
classifier.add(Convolution2D(32,3,2,input_shape=(200,200,3),activation = "relu"))
#add maxpooling layer of poilsize 2x2
classifier.add(MaxPooling2D(pool_size=(2,2)))
#add convolutional layer32, 3x3 filters, 2 stride relu activation
classifier.add(Convolution2D(32,3,2,input_shape=(200,200,3),activation = "relu"))
#add maxpooling layer of poilsize 2x2
classifier.add(MaxPooling2D(pool_size=(2,2)))
#flatten
classifier.add(Flatten())
#fully connected layer of 32 neuron relu activation
classifier.add(Dense(output_dim = 32,activation = "relu"))
#fully connected layer of 32 neuron relu activation
classifier.add(Dense(output_dim = 32,activation = "relu"))
#fully connected layer of 32 neuron relu activation
classifier.add(Dense(output_dim = 32,activation = "relu"))
#dropout regulariser
classifier.add(Dropout(0.2))
#fully connected layer of 32 neuron relu activation
classifier.add(Dense(output_dim = 32,activation = "relu"))
#fully connected output layer of 26 neuron softmax activation
classifier.add(Dense(26,activation="softmax"))
#select optimiser to be adam and loss categorical cross entropy bc 26 classes
classifier.compile("adam",loss="categorical_crossentropy",metrics=["accuracy"])

nb_train_samples = 1555
nb_validation_samples = 130
epochs = 40
batch_size = 16

# Dataset augumentation
train_datagen = ImageDataGenerator(
    rescale=1. / 255,
    shear_range=0.2,
    zoom_range=0.2,
    horizontal_flip=True)

test_datagen = ImageDataGenerator(rescale=1. / 255)

train_generator = train_datagen.flow_from_directory(
    Path(os.getcwd()+"./train"),
    target_size=(img_width, img_height),
    batch_size=batch_size,
    class_mode='categorical')
validation_generator = test_datagen.flow_from_directory(
    str(os.getcwd()+"./val"),
    target_size=(img_width, img_height),
    batch_size=batch_size,
    class_mode='categorical')
test_generator = test_datagen.flow_from_directory(
    str(os.getcwd()+"./test"),
    target_size=(img_width, img_height),
    batch_size=batch_size,
    class_mode='categorical')
#training model
history=classifier.fit_generator(
    train_generator,
    steps_per_epoch=nb_train_samples // batch_size,
    epochs=epochs,
    validation_data=validation_generator,
    validation_steps=nb_validation_samples // batch_size)
#saving model
classifier.save_weights('CNN.h5')
#accuracy calculate
scores = classifier.evaluate_generator(test_generator)
print("\n%s: %.2f%%" % (classifier.metrics_names[1], scores[1]*100))

#reads image of "a" from test folder and predicts
ximg = cv2.imread("./test/a/hand1_a_bot_seg_5_cropped.jpeg")
ximg=cv2.resize(ximg,(200,200))
out_put=classifier.predict(ximg.reshape(1,200,200,3))
idx=np.argmax(out_put)
ascii_idx=97+idx
print("The model predicts it is :")
print(chr(ascii_idx))

plt.plot(history.history['accuracy'])
plt.plot(history.history['val_accuracy'])
plt.title('model accuracy')
plt.ylabel('accuracy')
plt.xlabel('epoch')
plt.legend(['train', 'test'], loc='upper left')
plt.show()
# summarize history for loss
plt.plot(history.history['loss'])
plt.plot(history.history['val_loss'])
plt.title('model loss')
plt.ylabel('loss')
plt.xlabel('epoch')
plt.legend(['train', 'test'], loc='upper left')
plt.show()