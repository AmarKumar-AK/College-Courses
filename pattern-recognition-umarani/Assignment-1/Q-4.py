import math

f1=open("doc1.txt",'r')
if f1.mode == 'r':
    doc1=f1.read()
f1.close()

f2=open("doc2.txt",'r')
if f2.mode == 'r':
    doc2=f2.read()
f2.close()

k = doc1.replace(',','')
q = doc2.replace(',','')
k = k.replace('.','')
q = q.replace('.','')
k = k.replace('\n','')
q = q.replace('\n','')
k = k.lower()
q = q.lower()
p = k+" "+q

doc1_word_list=k.split(' ')
doc2_word_list=q.split(' ')
both_list=p.split(' ')
both_list_set=set(both_list)
doc1_dict = {}
doc2_dict = {}

for i in both_list_set:
    doc1_dict[i]=doc1_word_list.count(i)
    doc2_dict[i]=doc2_word_list.count(i)

sum=0
sq1=0
sq2=0

for i in both_list_set:
    sum += doc1_dict[i]*doc2_dict[i]
    sq1 += doc1_dict[i]*doc1_dict[i]
    sq2 += doc2_dict[i]*doc2_dict[i]

sq1 = math.sqrt(sq1)
sq2 = math.sqrt(sq2)

cos_dis = 1-(sum/(sq1*sq2))
print(f"Cosine distance between two docs is {cos_dis}")
