# Importing libraries using import keyword.
import math
import numpy as np
import matplotlib.pyplot as plt
import soundfile as sf
import sys


def main() :
    # Set the time difference to take picture of
    # the the generated signal.
    Time_difference = 0.0001
 
    # Generating an array of values
    Time_Array = np.linspace(0, 5, math.ceil(5 / Time_difference))

    # Actual data array which needs to be plot
    Data = 20*(np.sin(3 * np.pi * Time_Array))
    

    data, samplerate = sf.read(sys.argv[1])
    #sf.write('new_file.flac', data, samplerate)
    
    Data = data[0:80000]

    # Matplotlib.pyplot.specgram() function to
    # generate spectrogram
    plt.specgram(Data, Fs=6, cmap="rainbow")
    
    # Set the title of the plot, xlabel and ylabel
    # and display using show() function
    plt.title('Spectrogram Using matplotlib.pyplot.specgram() Method')
    plt.xlabel("DATA")
    plt.ylabel("TIME")
    plt.show()


if __name__ == "__main__" :
    main()
    
