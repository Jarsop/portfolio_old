#!/usr/bin/python
# -*- coding: utf-8-*-

import smtplib
import cgi
from email.MIMEMultipart import MIMEMultipart
from email.MIMEText import MIMEText

def index(req):
    form = cgi.FielStorage()
    name = form.getvalue('name')
    email = form.getvalue('email')
    phone = form.getvalue('phone')
    message = form.getvalue('message')
    #if name or email or phone or message:
    #    return False
    to = 'contact@mydomain.fr'
    email_subject = "Website Contact Form:  "+name
    email_body = "You have received a new message from your website contact form.\n\n"+"Here are the details:\n\nName: "+name+"\n\nEmail: "+email_address+"\n\nPhone: "+phone+"\n\nMessage:\n"+message
    headers = "From: noreply@mydomain.fr\n" # This is the email address the generated message will be from. We recommend using something like noreply@yourdomain.com.
    headers += "Reply-To: "+email_address
    fromaddr = 'noreply@mydomain.fr'
    msg = MIMEMultipart()
    msg['From'] = fromaddr
    msg['to'] = to
    msg['Subject'] = email_subject
    msg.attach(MIMEText(email_body, 'plain'))
    try:
        server = smtplib.SMTP('mail.mydomain.fr', 587)
        server.starttls()
        server.login('noreply@mydomain.fr', "pass")
        text = msg.as_string()
        server.sendmail(fromaddr, to, text)
        server.quit()
        return True
    except Exception as e:
        return False
