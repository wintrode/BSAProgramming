from skimage import data, io, filters
from skimage.transform import rescale, resize
import sys
import tensorflow as tf
import numpy as np
import json

def main() :
    dataset = []
    for image in sys.argv[3:] :
        img = io.imread(image, as_gray=False)
        #print(img.shape)
        #img = img[0:,60:420]
        img = img[50:274, 100:324]
        #img = resize(img, (224, 224))
        #print(img.shape)
        io.imshow(img)
        io.show()
        dataset.append(img)#(img,"unk"))
        

    model=tf.keras.models.load_model(sys.argv[1])
    fd = open(sys.argv[2])
    info = json.load(fd)
    fd.close()
    labels = info["default"]["features"]["label"]["names"]

    Z = model.predict(np.array(dataset))
    for z in Z :
        i = np.argmax(z)
        print(labels[i], ":", z[i])

if __name__=="__main__" :
    main()
