import sklearn
from sklearn.datasets import fetch_lfw_people

faces = fetch_lfw_people(min_faces_per_person=200)

from sklearn.decomposition import NMF
import time
import numpy as np
import matplotlib.pyplot as plt

mean = faces.data.mean(axis=0, keepdims=True) 
X = faces.data - mean

from sklearn.cluster import KMeans
from sklearn import metrics

scores_nmf = []
fitting = []
clustering = []
scoreing = []
l = [1, 2, 3]#, 4, 5, 6, 8, 9, 10, 12, 15, 20, 25, 40, 50, 80, 100, 150, 200, 300, 500]
for i in l:
  nmf = NMF(n_components=i,init='random', random_state=0, tol=0, max_iter=2000)
  now = time.time()
  Z = nmf.fit_transform(faces.data)
  fitting += [time.time()-now]; now = time.time()
  k_nmf = KMeans(n_clusters=2,random_state=10).fit( Z )
  clustering += [time.time()-now]; now = time.time()
  score = metrics.accuracy_score(faces.target, k_nmf.labels_)
  scoreing += [time.time()-now]; now = time.time()
  print(i, score)
  scores_nmf += [score]
  
np.save("scores", scores_nmf)
np.save("fitting", fitting)
np.save("clustering", clustering)
np.save("scoreing", scoreing)
print(score, fitting, clustering, scoreing, sep="\n")

plt.plot(l, scores_nmf)
plt.scatter(l, scores_nmf)
plt.xscale("log")
plt.savefig("fig.png")
plt.show()