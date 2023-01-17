import csv
import serial
import numpy
import matplotlib.pyplot as plt
from drawnow import *   # tanda bintang merupakan arti dari everything

    
intensitas = [] #tutup kurung merupakan tanda array kosong
temperature = [] #kosong karena data akan atang dari arduino nanti
fileName="D:\Program_file\data\myOutput.csv" #name of the CSV file generated


arduino = serial.Serial('COM3', 9600) #membuat objek arduino dengan membaca dari com4
plt.ion() #mulai memploting data


def grafik(): #mulai membuat fungsi grafik
    plt.plot(temperature) # kamu bisa rubah gaya dengan menambahkan fungsi setelah intensitas (*, fungsi)
    plt.xlabel('Intensitas')
    plt.ylabel('Sudut Perputaran')
    plt.show()
    plt.title('Simple Spektrofotometri')
    
while True:                             # akan ngeloop selamanya
    while (arduino.inWaiting()==0):     #program ini digunakan untuk  menunggu ada data masuk
        pass                            #jika tidak ada data masuk maka tidak melakukan apapun
    stringArduino = arduino.readline()  #variabel baru stringArduino untuk dibaca dalam readline
    datae = stringArduino[0:][:-2]
    pisahData = stringArduino.split(',') #fungsi dari variabel split adalah memisahkan data 
    cahaya = float( pisahData[0])       #print data pertama, float berfungsi sebagai pengubah string ke real number
    suhu = float( pisahData[1])         #print data kedua
    print cahaya, ',', suhu
    intensitas.append(cahaya)           #append memasukkan secara tumpuk data cahaya ke dalam array intensitas
    temperature.append(suhu)
    drawnow(grafik)                     #mulai menggambar fungsi grafik
    file = open(fileName, "a")
    file.write(datae + "\n")            #write data with a newline, bisa dirubah ke menu serapannya saja.
    #merubahnya mudah tinggal tulis file write cahaya + suhu
    plt.pause(.000001)                  #istirahat untuk sementara waktu
