def Receiver_data_parser(input_data):
  #This function parses through the data and fetches necessary info  
  #x = "1 - Temperature: 11.00000, SOC: 74.00000"
  intermediate_data = []
  temp_val = []
  soc_val = []
  intermediate_data.append(input_data.split("-"))
  data = ((intermediate_data[0][1].split(",")))
  temp_val.append( float((data[0].split(":"))[1].strip()) )
  soc_val.append( float((data[1].split(":"))[1].strip()) )
  return(temp_val,soc_val)

def min_value_calculator(data):
  #This function claculates the minimum value in a list of data
  return(min(data))

def max_value_calculator(data):
  #this function calculates the maximum value in a list of data
  return(max(data))

def sma_calculator(data):
  #this function calculates the simple moving average of the data in the list
  return(sum(data)/len(data))

def print_on_console(message):
  print(message)
