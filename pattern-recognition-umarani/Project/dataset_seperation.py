#this is to split original dataset into train test , val folders.
#drag this file into the dataset such that it is on the same level as a , b, c ..z folders (remove digits folders etc)
import os
import random
import shutil
from pathlib import Path

dirs_=[]
for root, dirs, files in os.walk(".", topdown=False):
   for name in dirs:
      dirs_.append(os.path.join(root, name))
for each in dirs_:
    try:
        os.mkdir(Path("../val"))
    except:
        print("already created")
    try:
        os.mkdir(Path("../val/"+each.split("\\")[1]))
    except:
        print("already created")
        
    
    os.chdir(each)
    files_list=os.listdir()
    random.shuffle(files_list)
    files_to_copy_ = [x for x in files_list if files_list.index(x)<5]
    for every in files_to_copy_:
        shutil.move(every,Path("../../"+"val/"+each.split("\\")[1]+"/"+every))
    os.chdir("../")
    print(os.getcwd())

dirs_=[]    
files_list =[]
files_to_copy_=[]
for root, dirs, files in os.walk(".", topdown=False):
   for name in dirs:
      dirs_.append(os.path.join(root, name))
for each in dirs_:
    try:
        os.mkdir(Path("../test"))
    except:
        print("already created")
    try:
        os.mkdir(Path("../test/"+each.split("\\")[1]))
    except:
        print("already created")
        
    
    os.chdir(each)
    files_list=os.listdir()
    random.shuffle(files_list)
    files_to_copy_ = [x for x in files_list if files_list.index(x)<5]
    for every in files_to_copy_:
        shutil.move(every,Path("../../"+"test/"+each.split("\\")[1]+"/"+every))
    os.chdir("../")
    print(os.getcwd())

dirs_=[]    
files_list =[]
files_to_copy_=[]    
for root, dirs, files in os.walk(".", topdown=False):
   for name in dirs:
      dirs_.append(os.path.join(root, name))
for each in dirs_:
    try:
        os.mkdir(Path("../train"))
    except:
        print("already created")
    try:
        os.mkdir(Path("../train/"+each.split("\\")[1]))
    except:
        print("already created")
        
    
    os.chdir(each)
    files_list=os.listdir()
    random.shuffle(files_list)
    files_to_copy_ = files_list
    for every in files_to_copy_:
        shutil.move(every,Path("../../"+"train/"+each.split("\\")[1]+"/"+every))
    os.chdir("../")
    print(os.getcwd())