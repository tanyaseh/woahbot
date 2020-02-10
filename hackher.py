from google.cloud import speech_v1
from google.cloud.speech_v1 import enums
import speech_recognition as sr
import serial
import time
# GOOGLE_APPLICATION_CREDENTIALS="C:\\Users\\Tanya\\Downloads\\MyProject-0416d14d70d8.json"

# client = speech_v1.SpeechClient()
arduino = serial.Serial('COM5', 115200, timeout=.1)
time.sleep(3)
# arduino.write('1'.encode());

r = sr.Recognizer()
mic = sr.Microphone()
# encoding = enums.RecognitionConfig.AudioEncoding.FLAC
# sample_rate_hertz = 44100
# language_code = "en-us"
# config = {'encoding': encoding, 'sample_rate_hertz': sample_rate_hertz, 'language_code': language_code}
# uri = "gs://cloud-samples-test/speech/audio.flac"
# harvard = sr.AudioFile('C:\\Users\\Tanya\\Documents\\HACKHER\\harvard.wav')
str = ""
arduino.write('0'.encode())


while (True):
    while (("catch" not in str) or ("whoa" not in str) or ("woah" not in str) or ("woe" not in str) or ("wow" not in str)):
        print(arduino.read())
        print("start recording")
        with mic as source:
            r.adjust_for_ambient_noise(source, duration=2)
            print("adjusted")
            audio = r.listen(source)
            print("finished recording")
        #response = client.recognize(config, audio)
        str = r.recognize_google(audio)
        print(str)
        if (("catch" in str) or ("whoa" in str) or ("woah" in str) or ("woe" in str) or ("wow" in str)):
            arduino.write('1'.encode())
            break
    time.sleep(5)
