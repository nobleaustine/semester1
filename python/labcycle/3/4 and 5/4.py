# 4. Design a class to store the details of a vehicle such as engine number, 
#    model, type, mileage, vendor, registration number, and owner name.
#    Design another class that holds the details of several vehicles and
#    provide functions to 
#     • Display the details of the collection
#     • Sort the collection according to mileage 
#     • Add, Delete and Modify the entries from the collection
#     • Store and Load the collection as a pickle file
#     • Filter the result according to the attributes and export it as a
#     report.
#     https://pbpython.com/pdf-reports.html

# importing required libraries
import pickle
import tabulate
from fpdf import FPDF

# class to store details of a vehicle
class details:
  __feature=['owner name','registration number','type','vendor','model','engine number','mileage']
  _car_details=dict.fromkeys(__feature,None)

# class to store the list of vehicles
class data_base(details):
  __vehicles_list=[]
  __filtered_list=[]

  # function to add new entries
  def add(self):
    i=1
    while(i==1):
      temp=self._car_details
      print("Enter the details of the vehicle")
      print(" ")
      temp['owner name']=input("Owner name : ")
      temp['registration number']=input("Registration number : ")
      temp['type']=input("Type of vehicle : ")
      temp['vendor']=input("Vendor : ")
      temp['model']=input("Model : ")
      temp['engine number']=input("Engine number : ")
      temp['mileage']=input("Mileage : ")
      print(" ")
      self.__vehicles_list.append(temp.copy())
      print("--- Entry Added ---")
      i= int(input("PRESS :1 to add / 0 to return to menu : "))
      print(" ")

  # function to sort by mileage
  def mileage_sort(self):
    l1=sorted(self.__vehicles_list,key = lambda i:i['mileage'])
    self.display("Sorted list",l1)

  # function to remove an exsisting entries
  def remove_entry(self):
    i=1
    while(i==1):
      temp=input("Enter registration number : ")
      print(" ")
      for i in self.__vehicles_list:
        if(i['registration number']==temp):
          self.__vehicles_list.remove(i)
          print("--- Entry Removed ---")
          break
      i= int(input("PRESS :1 to remove / 0 to return to menu : "))
      print(" ")
  
  # function to modify any attribute
  def modify(self):
    temp1=input("Enter registration number : ")
    print(" ")
    for i in self.__vehicles_list:
      if(i['registration number']==temp1):
        print("Choose from the choices to continue : ")
        print("1 to edit owner name")
        print("2 to edit registration number")
        print("3 to edit type")
        print("4 to edit vendor")
        print("5 to edit model")
        print("6 to edit engine number")
        print("7 to edit mileage")
        print(" ")
        temp2=input("Enter your choice : ")
        if(temp2==1):
          i['owner name']=input("Owner name : ")
          print(" ")
          print("--- Owner name modified ---")
          break

        elif(temp2==2):
          i['registration number']=input("Registration number : ")
          print(" ")
          print("--- Registration number modified ---")
          break

        elif(temp2==3):
          i['type']=input("Type of vehicle : ")
          print(" ")
          print("--- Type of vehicle modified ---")
          break

        elif(temp2==4):
          i['vendor']=input("Vendor : ")
          print(" ")
          print("--- Vendor modified ---")
          break

        elif(temp2==5):
          i['model']=input("Model : ")
          print(" ")
          print("--- Model modified ---")
          break

        elif(temp2==6):
          i['engine number']=input("Engine number : ")
          print(" ")
          print("--- Engine number modified ---")
          break

        elif(temp2==7):
          i['mileage']=input("Mileage : ")
          print("--- Mileage number modified ---")
          break
  
  # function to display the list
  def display(self,*args):
    header = ['Owner name','Registration number','Type of vehicle','Vendor name','Model','Engine number','Mileage']
    if(len(args)==0):
      r = [x.values() for x in self.__vehicles_list]
      print(tabulate.tabulate(r,header,tablefmt='grid'))
    elif (len(args)==2):
      print("\n",args[0])
      r = [x.values() for x in args[1]]
      print(tabulate.tabulate(r,header,tablefmt='grid'))

  # function to filter by a attribute
  def filter(self):
    print("Choose from the choices to continue : ")
    print(" ")
    print("1 to filter by owner name")
    print("2 to filter by registration number")
    print("3 to filter by type")
    print("4 to filter by vendor")
    print("5 to filter by model")
    print("6 to filter by engine number")
    print("7 to filter by mileage")
    print(" ")
    choice = int(input("Choice : "))
    

    if(choice==1):
      filter_key = (input("Enter the owner name to be filtered"))
      print(" ")
      self.__filtered_list = [i for i in self.__vehicles_list if i['owner name']== filter_key]
      self.display('Filtered List',self.__filtered_list)
      self.create_report()


    elif (choice==2):
      filter_key = (input("Enter the registration number to be filter"))
      print(" ")
      self.__filtered_list = [i for i in self.__vehicles_list if i['registration number']== filter_key]
      self.display('Filtered List',self.__filtered_list)
      self.create_report()


    elif (choice==3):
      filter_key = (input("Enter the type to be filter"))
      print(" ")
      self.__filtered_list = [i for i in self.__vehicles_list if i['type']== filter_key]
      self.display('Filtered List',self.__filtered_list)
      self.create_report()


    elif (choice==4):
      filter_key = (input("Enter the vendor to be filtered"))
      print(" ")
      self.__filtered_list = [i for i in self.__vehicles_list if i['vendor']== filter_key]
      self.display('Filtered List',self.__filtered_list)
      self.create_report()


    elif (choice==5):
      filter_key = (input("Enter the model to be filter"))
      print(" ")
      self.__filtered_list = [i for i in self.__vehicles_list if i['model']== filter_key]
      self.display('Filtered List',self.__filtered_list)
      self.create_report()


    elif (choice==6):
      filter_key = (input("Enter the engine number to be filter"))
      print(" ")
      self.__filtered_list = [i for i in self.__vehicles_list if i['engine number']== filter_key]
      self.display('Filtered List',self.__filtered_list)
      self.create_report()


    elif(choice==7):
      filter_key = float(input("Enter the mileage to filter"))
      print(" ")
      self.__filtered_list = [i for i in self.__vehicles_list if i['mileage']== filter_key]
      self.display('Filtered List',self.__filtered_list)
      self.create_report()
  
  # function to create pdf
  def create_report(self):
        keys_list= ['Owner name','Registration number','Type of vehicle','Vendor name','Model','Engine number','Mileage']
        line=''
        for i in keys_list:
            line+=i
            line+="       "
        
        pdf = FPDF()
        pdf.add_page()
        pdf.set_font("Arial",size = 10)
        pdf.cell(200,10,ln = 2,align = "C",txt = line)
        
        for entries in self.__filtered_list:
            add_text = ""
            new_list=entries.values()
            for data in new_list:
                add_text+=str(data)
                add_text+="                "
            pdf.cell(200,10,ln = 2,align = "C",txt = add_text)
        pdf.output('filtered.pdf')
  
  # function to load a pickle file
  def load_file(self,file_path):
    self.__vehicles_list = pickle.load(open(file_path,"rb"))
  
  # function to make a pickle file
  def make_file(self):
    pickle.dump(self.__vehicles_list,open("data.pkl","wb"))
    print("--- Pickle file created ---")

# main function
def main():
  i=1
  base1=data_base()
  while(i==1):
    print("Choose from the choices to continue : ")
    print(" ")
    print("1 to add entries")
    print("2 to delete entries")
    print("3 to modify entries")
    print("4 to filter by attributes")
    print("5 to sort by mileage")
    print("6 to display details")
    print("7 to create a pickle file")
    print("8 to load a pickle file")
    print(" ")
    choice= int(input("Choice : "))
    print(" ")
    if(choice==1):
      base1.add()

    elif(choice==2):
      base1.remove_entry()

    elif(choice==3):
      base1.modify()

    elif(choice==4):
      base1.filter()

    elif(choice==5):
      base1.mileage_sort()

    elif(choice==6):
      base1.display()
      
    elif(choice==7):
      base1.make_file()

    elif(choice==8):
      file_path = input("Enter the file name : ")
      base1.load_file(file_path)
      base1.display()
    i= int(input("PRESS :1 to continue / 0 to exit the program : "))
    print(" ")

main()