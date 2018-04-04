# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    MailSender.py                                    .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: brobicho <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/04/04 14:37:21 by brobicho     #+#   ##    ##    #+#        #
#    Updated: 2018/04/04 18:25:59 by brobicho    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

import os
import smtplib
import getpass

try:
    fromaddr = input("Veuillez entrer votre adresse e-mail ou votre nom : ")
    toaddrs = input("Veuillez renseigner votre destinataire : ")
    print("Corps du message (2x Enter ou CTRL+D pour valider) : ")
    lines = []
    while True:
        line = input()
        if line:
            lines.append(line)
        else:
            break
    text = '\n'.join(lines)
    username = input("Nom d'utilisateur : ")
    password = getpass.getpass("Mot de passe : ")
    serveraddr = input("Adresse du serveur SMTP : ")
    serverport = input("Port du serveur SMTP : ")
    server = smtplib.SMTP(serveraddr, int(serverport))
    server.ehlo()
    server.starttls()
    server.ehlo()
    server.login(username, password)
    server.sendmail(fromaddr, toaddrs, text)
    print("Succes !")
    server.quit()
except:
    os.system("clear")
    print("Erreur lors de l'envoi du mail. Veuillez verifier les informations fournies.")
