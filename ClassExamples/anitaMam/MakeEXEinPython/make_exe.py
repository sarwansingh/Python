import webbrowser

def main():
    print("Openning Favorite Sites")


with open('site.txt.txt', mode='rb') as fobj:
    try:
        for num, url in enumerate(fobj):
            webbrowser.open_new_tab(url.strip())
    except Exception as e:
        print(e)

    print("\nEnjoy!")

if __name__ == '__main__' : main()

'''

on the anaconda prompt
 install pyinstaller                                                                                                     
then make make_exe.py file and give the following command                                                               
pyinstaller.exe --onefile make_exe.py                                                                                   
this will create a build and dist folder in the command path                                                            
the dist folder will contain the target .exe file                                                                       
save the site.txt or any another txt file used in the .py file in dist folder  
''''
