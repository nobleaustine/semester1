
# Importing required libraries
from tkinter import *
from tkinter import ttk

from numpy import delete
from tkinter import filedialog
import pickle
from fpdf import FPDF

#Designing a class to represent a vehicle
class car:
    #Defining a constructor
    def __init__(self,C_EngNo,C_Model,C_Type,C_Mileage,C_Vendor,C_RegNo,C_OwnName):
        self.C_EngNo = C_EngNo
        self.C_Model = C_Model
        self.C_Type = C_Type
        self.C_Mileage =C_Mileage
        self.C_Vendor = C_Vendor
        self.C_RegNo = C_RegNo
        self.C_OwnName = C_OwnName
    #Function to show the details of the car
    def show(self):
        print(self.C_EngNo,self.C_Model,self.C_Type,self.C_Mileage,self.C_Vendor,self.C_RegNo,self.C_OwnName,sep = "\t")
        print()

#Class to hold the details of several vehicles
class CarDetails:
    def __init__(self):
        self.Car_list = list() #list of car objects
        self.To_write_list = list() #list of car details
    def Load_from_file(self,filename):
        Car_file = open(filename,"rb")
        Car_read_data = pickle.load(Car_file) 
        for i in Car_read_data:
            A = car(i[0],i[1],i[2],i[3],i[4],i[5],i[6])
            self.Car_list.append(A)
            self.To_write_list.append(i)
        Car_file.close()
    def add_Car(self,Car):
        self.Car_list.append(Car)
    def show_details(self):
        print("No.\tEngNo.\tModel\tType\tMileage\tVendor\tRegNo.\tOwner\n")
        No = 1
        for CarDetail in self.Car_list:
            print(No,end = "\t")
            No+=1
            CarDetail.show()
            print()
    def Sort_Mileage(self):
        #lambda for sorting
        S_list = sorted(self.To_write_list,key = lambda x : x[3])
        Car_list_index = 0
        self.To_write_list = S_list
        for i in S_list:
            A = car(i[0],i[1],i[2],i[3],i[4],i[5],i[6])
            self.Car_list[Car_list_index] = A
            Car_list_index+=1
    def Delete_car(self,RegNo):
        check = False
        del_index = 0
        for i in self.Car_list:
            if i.C_RegNo == RegNo:
                self.Car_list.pop(del_index)
                check = True
            del_index+=1
        if not check:
            print(RegNo,"Does not Exist")
    def Modify_car(self,RegNo,Detail_name,Change_value):
        check = False
        for i in self.Car_list:
            if i.C_RegNo == RegNo:
                check = True
                if i.Detail_name:
                    self.Car_list[i].Detail_name = Change_value
                else:
                    print(Detail_name,"is not a valid detail")
        if not check:
            print(RegNo,"is not a valid parameter")
    def Save_Details(self,filename):
        #Save as a pickle file
        #opening in write binary mode
        Details = open(filename,"wb")
        Details.truncate()
        print(self.To_write_list)
        pickle.dump(self.To_write_list,Details)
        Details.close()
    def Create_report(self,filename):
        pdf = FPDF()
        pdf.add_page()
        pdf.set_font("Arial",size = 10)
        pdf.cell(200,10,ln = 2,align = "C",txt = "No.\tEngNo.\tModel\tType\tMileage\tVendor\tRegNo.\tOwner\n")
        
        for entries in self.To_write_list:
            add_text = ""
            for data in entries:
                add_text+=str(data)
                add_text+="\t"
            pdf.cell(200,10,ln = 2,align = "C",txt = add_text)
        pdf.output(filename)
#Constants
scr = Tk()
scr.geometry("900x400+20+30")
scr.configure(bg = "#2B55A9")
scr.title("Vehicle Sale Data")
text= Label(scr, font=('Times New Roman',15,'bold'),text="VEHICLE DATA",bg="#2B55A9")
text.pack()
CarData = CarDetails() #Creating a object to store all car data
DataFrame = LabelFrame(scr,text="Datas",bg = "#2B55A9")
DataFrame.pack(expand="yes",side=RIGHT)
CarDisplay = ttk.Treeview(DataFrame)

def data_screen_frame():
    count=0
    #Setting the Data Table display
    #Setting the display for data
    CarDisplay['columns'] = ("EngNo","Model","Type","Mileage","Vendor","RegNo","Owner")
    CarDisplay.column("#0",width=0,minwidth=3)
    CarDisplay.column("EngNo",anchor = W,minwidth=10,width=50)
    CarDisplay.column('Model',anchor = W,minwidth=10,width=50)
    CarDisplay.column('Type',anchor = W,minwidth=10,width=50)
    CarDisplay.column('Mileage',anchor = W,minwidth=20,width=50)
    CarDisplay.column('Vendor',anchor = W,minwidth=20,width=50)
    CarDisplay.column('RegNo',anchor = W,minwidth=20,width=50)
    CarDisplay.column('Owner',anchor = W,minwidth=20,width=50)
    #setting the headings
    CarDisplay.heading("#0",text = " ",anchor=W )
    CarDisplay.heading("EngNo",text = "Engine No.",anchor = W)
    CarDisplay.heading("Model",text = "Model",anchor = W)
    CarDisplay.heading("Type",text ="Type",anchor = W)
    CarDisplay.heading("Mileage",text = "Mileage",anchor = W)
    CarDisplay.heading("Vendor",text = "Vendor",anchor = W)
    CarDisplay.heading("RegNo",text = "Reg. No.",anchor = W)
    CarDisplay.heading("Owner",text = "Owner",anchor = W)
    List_of_cars = CarData.To_write_list
    for i in List_of_cars:
        show_Values = tuple(i)
        CarDisplay.insert(parent = "",index = 'end',values=show_Values)
    CarDisplay.pack()
   
#Defining Button actions

#Creating a frame for the Input details
In_Frame = LabelFrame(scr,text = "Input",bg = "#2B55A4")
In_Frame.pack(fill="x",expand="yes",padx = 20)
In_EngNo = StringVar(None)
#Creating Labels and respective entry boxes
In_EngNo_Label = Label(In_Frame,text = "Engine No",bg='#A9FAFF')
In_EngNo_Label.grid(row = 0,column=0,padx=10,pady=10)
In_EngNo = Entry(In_Frame)
In_EngNo.grid(row=0,column=1,padx=10,pady=10)

In_Model_Label = Label(In_Frame,text = "Model",bg='#A9FAFF')
In_Model_Label.grid(row = 1,column=0,padx=10,pady=10)
In_Model = Entry(In_Frame)
In_Model.grid(row=1,column=1,padx=10,pady=10)

In_Type_Label = Label(In_Frame,text = "Type",bg='#A9FAFF')
In_Type_Label.grid(row = 2,column=0,padx=10,pady=10)
In_Type = Entry(In_Frame)
In_Type.grid(row=2,column=1,padx=10,pady=10)

In_Mileage_Label = Label(In_Frame,text = "Mileage",bg='#A9FAFF')
In_Mileage_Label.grid(row = 0,column=2,padx=10,pady=10)
In_Mileage = Entry(In_Frame)
In_Mileage.grid(row=0,column=3,padx=10,pady=10)

In_Vendor_Label = Label(In_Frame,text = "Vendor",bg='#A9FAFF')
In_Vendor_Label.grid(row = 1,column=2,padx=10,pady=10)
In_Vendor = Entry(In_Frame)
In_Vendor.grid(row=1,column=3,padx=10,pady=10)

In_Regno_Label = Label(In_Frame,text = "Reg No",bg='#A9FAFF')
In_Regno_Label.grid(row = 2,column=2,padx=10,pady=10)
In_RegNo = Entry(In_Frame)
In_RegNo.grid(row=2,column=3,padx=10,pady=10)

In_Owner_Label = Label(In_Frame,text = "Owner",bg='#A9FAFF')
In_Owner_Label.grid(row = 4,column=0,padx=10,pady=10)
In_Owner = Entry(In_Frame)
In_Owner.grid(row=4,column=1,padx=10,pady=10)

def clear_inputs():
    #To clear the inputs on screen
    In_EngNo.delete(0,END)
    In_Model.delete(0,END)
    In_Type.delete(0,END)
    In_Mileage.delete(0,END)
    In_Vendor.delete(0,END)
    In_RegNo.delete(0,END)
    In_Owner.delete(0,END)

def add_to_entry_box():
    clear_inputs()
    #Select the record number
    sel_record = CarDisplay.focus()
    #Selecting values of the record
    rec_values = CarDisplay.item(sel_record,'values')
    #outputting to entry box
    In_EngNo.insert(0,rec_values[0])
    In_Model.insert(0,rec_values[1])
    In_Type.insert(0,rec_values[2])
    In_Mileage.insert(0,rec_values[3])
    In_Vendor.insert(0,rec_values[4])
    In_RegNo.insert(0,rec_values[5])
    In_Owner.insert(0,rec_values[6])

def Delete_record():
    sel_record = CarDisplay.focus()
    rec_values = CarDisplay.item(sel_record,'values')
    #To Remove Data from screen
    to_delete = CarDisplay.selection()[0]
    CarDisplay.delete(to_delete)
    #To remove from CarData
    CarData.Delete_car(rec_values[5])



def Add_the_record():
    add_data = (In_EngNo.get(),In_Model.get(),In_Type.get(),
        int(In_Mileage.get()),In_Vendor.get(),In_RegNo.get(),In_Owner.get())
    
    to_Add_Car = car(In_EngNo.get(),In_Model.get(),In_Type.get(),int(In_Mileage.get())
        ,In_Vendor.get(),In_RegNo.get(),In_Owner.get())
    CarData.add_Car(to_Add_Car)
    CarDisplay.insert(parent = "",index = 'end',values=add_data)
    clear_inputs

def Load_File():
    scr.filename = filedialog.askopenfilename(initialdir="/",
        title="Select Pickle File",filetypes=(("pickle files","*.dat"),("All Files","*.*")))
    CarData.Load_from_file(scr.filename)
    for i in CarData.To_write_list:
        show_Values = tuple(i)
        CarDisplay.insert(parent = "",index = 'end',values=show_Values)
    
def Save_File():
    scr.filename = filedialog.askopenfilename(initialdir="/",
        title="Select pickle File",filetypes=(("File to save","*.dat"),("All Files","*.*")))    
    CarData.Save_Details(scr.filename)

def Sort_mileage():
    #Sorting object data by Mileage
    CarData.Sort_Mileage()
    #Deleting items on window
    for data in CarDisplay.get_children():
        CarDisplay.delete(data)
    for i in CarData.To_write_list:
        show_Values = tuple(i)
        CarDisplay.insert(parent = "",index = 'end',values=show_Values)
def Save_as_pdf():
    scr.filename = filedialog.askopenfilename(initialdir="/",
        title="Select Pdf File",filetypes=(("pdf files","*.pdf"),("All Files","*.*"))) 
    CarData.Create_report(scr.filename)

def Buttons_Frame():
    ButtonFrame = LabelFrame(scr,text = "Options",bg = "#2B55A9")
    ButtonFrame.pack()

    AddRec_button = Button(ButtonFrame,text = "Add",command=Add_the_record,activebackground='#FFA9A9',bg='#A9FAFF')
    AddRec_button.grid(row=0,column=0,padx=10,pady=10)

    Modify_button = Button(ButtonFrame,text = "Modify",activebackground='#FFA9A9',bg='#A9FAFF')
    Modify_button.grid(row=1,column=0,padx=10,pady=10)

    Open_button = Button(ButtonFrame,text = "Open File",command=Load_File,activebackground='#FFA9A9',bg='#A9FAFF')
    Open_button.grid(row=2,column=0,padx=10,pady=10)

    Sort_button = Button(ButtonFrame,text = "Sort by Mileage",command=Sort_mileage,activebackground='#FFA9A9',bg='#A9FAFF')
    Sort_button.grid(row=0,column=1,padx=10,pady=10)

    Delete_button = Button(ButtonFrame,text = "Delete Entry",command=Delete_record,activebackground='#FFA9A9',bg='#A9FAFF')
    Delete_button.grid(row=1,column=1,padx=10,pady=10)

    Save_button = Button(ButtonFrame,text = "Save Data",command=Save_File,activebackground='#FFA9A9',bg='#A9FAFF')
    Save_button.grid(row=2,column=1,padx=10,pady=10)

    Report_button = Button(ButtonFrame,text = "Save PDF",command=Save_as_pdf,activebackground='#FFA9A9',bg='#A9FAFF')
    Report_button.grid(row=0,column=3,padx=10,pady=10)

    Show_button = Button(ButtonFrame,text = "Show Selection",command=add_to_entry_box,activebackground='#FFA9A9',bg='#A9FAFF')
    Show_button.grid(row=1,column=3,padx=10,pady=10)

    Clear_Button = Button(ButtonFrame,text = "Clear",command=clear_inputs,activebackground='#FFA9A9',bg='#A9FAFF')
    Clear_Button.grid(row=2,column=3,padx=10,pady=10)

Buttons_Frame()
data_screen_frame() 
scr.mainloop()