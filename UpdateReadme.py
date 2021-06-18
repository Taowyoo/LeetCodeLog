'''
Author: Nick Cao
Date: 2021-06-06 14:30:52
LastEditTime: 2021-06-18 13:50:07
LastEditors: Nick Cao
Description: 
FilePath: /LeetCodeLog/UpdateReadme.py
'''

import csv
import os
from mdutils.mdutils import MdUtils

solutions_path = "src"
csv_path = "Summary.csv"

exts = ['cpp','java','js','py','rs']
cols_names = ['No','Name','C++','Java','JavaScript','Python','Rust']

def save_to_csv(path: str, data: list[list[str]]):
    print("Updating {}".format(path))
    with open(path, 'w', newline='') as csvfile:
        spamwriter = csv.writer(csvfile)
        for row in data:
            spamwriter.writerow(row)
    print("Updated {}".format(path))
    
def get_solution_data(solution_path: str) -> list[list[str]]:
    head = [cols_names]
    data = []
    # iterate each problem dir
    with os.scandir(solution_path) as it:
        for entry in it:
            if entry.is_dir():
                # get id and name of the problem
                names = entry.name.split(".")
                row = [names[0],names[1]]
                
                # check solutions
                with os.scandir(entry.path) as it2:
                    # solutions_ext = [x.name.split('.')[-1] for x in it2 if x.is_file()]
                    # finished = ['Done' if ext in solutions_exts else '' for ext in exts]
                    solutions_dir = [x for x in it2 if x.is_file()]
                    finished = ['']*len(exts)
                    for dir in solutions_dir:
                        ext = dir.name.split('.')[-1]
                        finished[exts.index(ext)]=dir.path
                        pass
                row += finished
                data.append(row)
    data.sort(key=lambda l : int(l[0]))
    return head + data

def update_readme(data: list[list[str]]):
    print("Updating {}".format("README.md"))
    mdFile = MdUtils(file_name='README',title='LeetCodeLog')
    mdFile.new_line()
    mdFile.new_line("This is my record of LeetCode solutions.")
    mdFile.new_line()
    col_sz = len(data[0])
    row_sz = len(data)

    list_of_strings = data[0]
    for row in data[1:]:
        for i in range(-len(exts),0):
            if row[i]!='' :
                # row[i] = "[Done]({})".format(row[i])
                row[i] = mdFile.new_inline_link(link=row[i], text=exts[i])
                pass
        list_of_strings.extend(row)

    mdFile.new_table(columns=col_sz, rows=row_sz, text=list_of_strings, text_align='left')
    mdFile.create_md_file()
    print("Updated {}".format("README.md"))

if __name__ == "__main__":
    data = get_solution_data(solutions_path)
    save_to_csv(csv_path,data)
    update_readme(data)
