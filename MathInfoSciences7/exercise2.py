#%%time
import sklearn
from sklearn.datasets import fetch_lfw_people
faces = fetch_lfw_people(min_faces_per_person=200)
print(faces.target_names)
print(faces.target.shape)
print(faces.data.shape)