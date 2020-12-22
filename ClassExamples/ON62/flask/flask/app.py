from flask import *  

app = Flask(__name__)  

data=[
    {
        'name':'Audrin',
        'place': 'kaka',
        'mob': '7736'
    },
    {
        'name': 'Stuvard',
        'place': 'Goa',
        'mob' : '546464'
    }
]


@app.route('/')  
def msg():
	return " I am index : demo of Data passing " 

@app.route('/file')
def openfile():
	return render_template("first.html" , all_data=data)

@app.route('/html')
def message():  
      return "<html><body><h1>Hi, welcome to the website</h1></body></html>"  

if __name__ == '__main__':  
   app.run(debug = True)  