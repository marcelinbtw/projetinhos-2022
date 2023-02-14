import speech_recognition as sr
import pyttsx3
import datetime
import webbrowser as browser
import sys
import turtle
import os
import random
import requests


#Variáveis para o funcionmento do TTS e reconhecimento de voz
audio = sr.Recognizer()
maquina = pyttsx3.init()


#Consumo da API OpenWeather
API_KEY = "0b439fb153f14ab92ba2e039d3ee30d4"
cidade = "uberlandia"
link = f"https://api.openweathermap.org/data/2.5/weather?q={cidade}&appid={API_KEY}&lang=pt_br"
requisicao = requests.get(link)
requisicao_dic = requisicao.json()
descricao = requisicao_dic['weather'][0]['description']
temperatura = requisicao_dic['main']['temp'] - 273.15


#Função para executar o comando dito pelo usuário
def executa_comando():
    try:
        with sr.Microphone() as source:
            print("Ouvindo...")
            voz = audio.listen(source)
            comando = audio.recognize_google(voz, language="pt-BR")
            comando = comando.lower()
            if "judite" in comando:
                print(comando)
                maquina.say(comando)
                maquina.runAndWait()

    except:
        print("Microfone não está ok")
    return comando

#Função para a execução do comando requisitada pelo usuário.
def comando_Voz_Usuario():
    comando = executa_comando()

    if 'beijinhos' in comando:
        maquina.say("beijinhos Estou desligando")
        maquina.runAndWait()
        sys.exit()

    elif 'horas' in comando:
        hora = datetime.datetime.now().strftime('%H:%M')
        maquina.say("Agora são" + hora)
        maquina.runAndWait()

    elif 'pesquisar' in comando and 'google' in comando:
        comando = comando.replace('pesquisar', '')
        comando = comando.replace('no google', '')
        browser.open(f'https://google.com/search?q={comando}')

    elif 'procurar' in comando and 'youtube' in comando:
        comando = comando.replace('pesquisar', '')
        comando = comando.replace('procurar','')
        comando = comando.replace('no youtube','')
        browser.open(f'https://youtube.com/results?search_query={comando}')

    elif 'abrir' in comando and 'google' in comando :
        os.startfile("C:\Program Files\Google\Chrome\Application\chrome.exe")
    elif 'abrir' in comando and 'minecraft' in comando :
        os.startfile("C:\XboxGames\Minecraft Launcher\Content\Minecraft.exe")

    elif 'sortear' in comando and 'número' in comando :
        numero = random.randint(0,100)
        numero = str(numero)
        maquina.say("O número sorteado é" + numero)
        maquina.runAndWait()

    #Reprodução da Assistente para informar o Clima da região, com a API OpenWeather (linha 14)
    elif 'clima' in comando:
        maquina.say("O clima em uberlandia está %.2f º Celsius e l á fora também está" %temperatura)
        maquina.say(descricao)
        maquina.runAndWait()


#Entrada de dados da Assistente, ela está escutando o usuário.
def main():
    maquina.say("Ola! eu sou Judite. Em que posso ajudar?!!")
    maquina.runAndWait()
    while True:
        comando_Voz_Usuario()
main()