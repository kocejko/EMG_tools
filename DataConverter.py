#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Jul 31 22:11:58 2018

@author: kocej
"""

import csv
import numpy as np
import re

#from tkinter import *
import tkinter
from tkinter import filedialog

def open_convert():
    root = tkinter.Tk()
    root.withdraw()
    file_name = filedialog.askopenfilename( filetypes = (("all","*.*"),("Text","*.txt")))
    #i = 0
    s_no = 1500
    results = []
    out = np.zeros([0,1500,4])
    with open(file_name) as csvfile:
        for line in csvfile:
            if len(line.split()) == 0:  
                print("pusto")
            elif '#' in line:
                if len(results) > 1:
                    #print(''.join(results))
                    print(len(results))
                    if len(results) == s_no:
                        a = np.array(results[0:], dtype = float)
                        a2 = a.reshape(1,1500,4)
                        out = np.vstack([out,a2])
                    results = []
            else:
                temp_l = line.strip()                
                results.append(temp_l[:-1].split(';'))
        
        #print(len(results))
        if len(results) == s_no:
            a = np.array(results[0:], dtype = float)
            a2 = a.reshape(1,1500,4)
            out = np.vstack([out,a2])
        
        #print(a2)

    print("cos sie dziej")
    
    return out