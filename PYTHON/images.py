#!/usr/bin/python3

# from scikit-image.org

from skimage import data, io, filters
import sys

def main() :
    if len(sys.argv) > 1:
        image = io.imread(sys.argv[1], as_gray=True)
    else:
        image = data.coins()
    print(image.shape)
    io.imshow(image)
    io.show()

    # ... or any other NumPy array!
    # find the edges in an image
    edges = filters.sobel(image)
    io.imshow(edges)
    io.show()


if __name__ == "__main__" :
    main()
    
