'''
Author: Nick Cao
Date: 2021-06-06 14:30:52
LastEditTime: 2021-06-06 15:34:48
LastEditors: Nick Cao
Description: 
FilePath: \LeetCodeLog\GenerateCSV.py
'''

import csv
import os

solution_path = "src"
csv_path = "Summary.csv"

exts = ['cpp','java','js','py','rs']

def save_to_csv(path: str, data: list[list[str]]):
    print("Updating {}".format(path))
    with open(path, 'w', newline='') as csvfile:
        spamwriter = csv.writer(csvfile)
        for row in data:
            spamwriter.writerow(row)
    print("Updated {}".format(path))
    
def get_solution_data(solution_path: str) -> list[list[str]]:
    data = [['No','Name','C++','Java','Javascript','Python','Rust']]
    # iterate each problem dir
    with os.scandir(solution_path) as it:
        for entry in it:
            if entry.is_dir():
                # get id and name of the problem
                names = entry.name.split(". ")
                row = [names[0],names[1]]
                
                # check solutions
                with os.scandir(entry.path) as it2:
                    solutions_exts = [x.name.split('.')[-1] for x in it2 if x.is_file()]
                    finished = ['Done' if ext in solutions_exts else '' for ext in exts]
                row += finished
                data.append(row)
    return data


if __name__ == "__main__":
    # cur_script_path = os.path.dirname(os.path.realpath(__file__))
    data = get_solution_data(solution_path)
    save_to_csv(csv_path,data)
