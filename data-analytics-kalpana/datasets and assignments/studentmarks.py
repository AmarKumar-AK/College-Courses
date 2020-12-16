#!/usr/bin/env python
# coding: utf-8

# In[9]:


import pandas as pd
import numpy as np
import scipy
from scipy import stats


# In[4]:


# read excel file
data = pd.read_excel("StudentsMarks.xlsx")
print(data)


# In[5]:


# printing Total column
x= data['Total']
print(x)


# In[6]:


np.mean(x) # mean


# In[7]:


np.median(x) # median


# In[12]:


# np.mode(x)


# In[10]:


# mode is not available in numpy
stats.mode(x) # mode


# In[11]:


np.var(x) # variance


# In[22]:


# first quartile
q1=np.percentile(x,50)
print(q1)


# In[17]:


min(x) # minimum from Total column


# In[18]:


# maximum from Total column
max(x)


# In[23]:


# third quartile
q3=np.percentile(x,75)
print(q3)


# In[24]:


# inter quartile
IQ=q3-q1
print(IQ)


# In[26]:


import statistics as st


# In[30]:


st.pstdev(x) # population standard deviation


# In[28]:


st.stdev(x) # sample standard deviation


# In[32]:


from scipy.stats import skew
skew(x) #skewness


# In[33]:


from matplotlib import pyplot as plt


# In[34]:


plt.boxplot(x,sym='x') # boxplot
plt.show()


# In[ ]:




