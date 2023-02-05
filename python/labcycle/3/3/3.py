# 3. Create an account in Kaggle.com
    # Download iris dataset from the link 
    # https://www.kaggle.com/datasets/saurabh00007/iriscsv
    # Load it using pandas library
    #   Prepare the following charts :
    #     • Bar chart showing the frequency of species column
    #     • Apply PCA to get two principle components and show the data 
    #       distribution as a scatter plot. (use functon from sklearn)
    #     • Show the distribution of each attribute as histogram.
    #       Note: for visualization, you can either use matplotlib or seaborn

# importing requiered libraries
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from matplotlib import colors
from sklearn.decomposition import PCA
from sklearn.preprocessing import StandardScaler

d = pd.read_csv("Iris.csv")  # Reading Iris.csv using pandas

 # Plotting bar graph with frequencies of species
species_list = d['Species'].value_counts()
species_list.plot(kind = "bar",color=['b','g','r'],xlabel = 'species',ylabel= 'frequency')
plt.title("Bar Graph")
plt.show()


# Appling PCA to have 2 principal compnents
x  = d.iloc[:,:-1] # Removing species column
print(x)
x = StandardScaler().fit_transform(x) # normalising the data set
print("Mean",np.mean(x)) # After normalisation mean = 0 and std dvn = 1
print("STD Dvn : ",np.std(x))

# Calculating PCA to have 2 components
pca_iris =  PCA(n_components=2)
print(pca_iris)
principal_components_iris = pca_iris.fit_transform(x)
print(principal_components_iris)

# Creating a data frame with PCA Values
principal_iris_DF = pd.DataFrame(data=principal_components_iris,
        columns = ['PC1','PC2'])
principal_iris_DF.tail()
print(principal_iris_DF)

# Plotting from the principal components
plt.figure()
plt.xlabel("principal component 1")
plt.ylabel("principal component 2")
targets = ['Iris-setosa','Iris-versicolor','Iris-virginica']
colors = ['b','g','r']
for target,color in  zip(targets,colors):
    indices_to_Keep = d['Species'] == target
    plt.scatter(principal_iris_DF.loc[indices_to_Keep,'PC1'],
    principal_iris_DF.loc[indices_to_Keep,"PC2"],c = color,label = target )
plt.legend()
plt.show()


# To display each attribute as a histogram

def plot_hist(Att_name,Hcolor,title,xtitle):
    d[Att_name].hist(color = Hcolor)
    plt.xlabel(xtitle)
    plt.ylabel('frequency')
    plt.title(title)
    plt.show()

plot_hist('SepalLengthCm','r','Sepal length distribution','sepal length(cm)')
plot_hist('SepalWidthCm','yellow','Sepal Width distribution','sepal width(cm)')
plot_hist('PetalLengthCm','grey','Petal length distribution','petal length(cm)')
plot_hist('PetalWidthCm','blue','Petal width distribution','petal width(cm)')
