#!/usr/bin/env python
# -*- coding: utf-8 -*-

import smtplib
import cgi
from email.MIMEMultipart import MIMEMultipart
from email.MIMEText import MIMEText
from flask import Flask,render_template,request
from flask_nav.elements import Navbar, View
from flask_nav import Nav
from flask_bootstrap import Bootstrap

#déclare le serveur flask
app = Flask(__name__, static_folder='static', static_url_path='/static')

bootstrap = Bootstrap(app)
#j'instancie le plug-in flask-Nav
nav = Nav()
#je déclare le plug-in dans l'application
nav.init_app(app)
#je déclare une barre de navigation contenant les routes
mynavbar = Navbar(
    'mysite',
    View('Home', 'index'),
    View('1er Exemple', 'hello'),
    View('template Exemple', 'hello2'),
    View('BootStrap Exemple', 'hello3'),
    View('BootStrap et Nav Exemple', 'hello4'),
)
#je donne au plug-in ma barre de navigation
nav.register_element('top', mynavbar)

#crée la route web de la racine du site
#et la lie à la fonction index
@app.route("/")
def index():
    return render_template('index.html')

@app.route("/contact_me", methods=['POST'])
def contact_me():
    name = request.form['name']
    email = request.form['email']
    phone = request.form['phone']
    message = request.form['message']
    to = 'contact@mydomain.fr'
    email_subject = "Website Contact Form:  "+name
    email_body = "You have received a new message from your website contact form.\n\n"+"Here are the details:\n\nName: "+name+"\n\nEmail: "+email+"\n\nPhone: "+phone+"\n\nMessage:\n"+message
    headers = "From: noreply@mydomain.fr\n" # This is the email address the generated message will be from. We recommend using something like noreply@yourdomain.com.
    headers += "Reply-To: "+email
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
        return """<div class='alert alert-success'><button type='button' class='close' data-dismiss='alert' aria-hidden='true'>&times;</button><strong>Your message has been sent. </strong></div>"""
    except Exception as e:
        return """<div class='alert alert-danger'><button type='button' class='close' data-dismiss='alert' aria-hidden='true'>&times;</button><strong>Sorry """ + name + """, it seems that my mail server is not responding. Please try again later!</div>"""


@app.route('/googlef1ff8694d3e902a5.html')
def google():
    return render_template('googlef1ff8694d3e902a5.html')
#on crée la nouvelle route et on la lie à fonction Hello
@app.route('/hello')
@app.route('/hello/<name>')
def hello(name=None):
    if name == None :
        #Si le nom n'est pas dans l'url, je tente de l'extraire depuis la requête
        name = request.args.get('name','Dude')
    return render_template('hello.html', name=name)

@app.route('/hello2')
@app.route('/hello2/<name>')
def hello2(name=None):
    if name == None :
        name = request.args.get('name','Dude')
    return render_template('hello2.html', name=name)

@app.route('/hello3')
@app.route('/hello3/<name>')
def hello3(name=None):
    if name == None :
        name = request.args.get('name','Dude')
    return render_template('hello3.html', name=name)

@app.route('/hello4')
@app.route('/hello4/<name>')
def hello4(name=None):
    if name == None :
        name = request.args.get('name','Dude')
    return render_template('hello4.html', name=name)

if __name__ == '__main__':
    app.run(debug=True)
