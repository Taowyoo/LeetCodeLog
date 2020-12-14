import os
path = "."
dirs = []
with os.scandir(path) as path_it:
    for entry in path_it:
        if not entry.name.startswith('.') and entry.is_dir():
            print(entry.path)
            dirs.append(entry.path)

print(dirs)

dirs_to_scan = dirs.copy()
dirs_to_scan.remove('.\\notes')
print(dirs_to_scan)

file_dict = {}
for d in dirs_to_scan:
    with os.scandir(d) as path_it:
        for entry in path_it:
            if not entry.name.startswith('.') and entry.is_file():
                file_ext = entry.name.split('.')[-1]
                if file_ext in file_dict:
                    file_dict[file_ext].append(entry.path)
                else:
                    file_dict[file_ext] = [entry.path]

                
import pprint

pp = pprint.PrettyPrinter()
pp.pprint(file_dict)

for k,v in file_dict.items():
    print(f'There are {len(v)} .{k} files')
