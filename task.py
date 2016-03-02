#!/usr/bin/python3

import argparse, os, shutil, fileinput
import string
basepath = "/home/oleg/coding/olimp"


def replaceJava(task):
    template_str = open('Main.java')
    temp = string.Template(template_str)
    out_str = temp.substitute(task)
    open('Main.java', 'w').write(out_str)

def createTask(task):
    task['basepath'] = task['contest']['basepath'] + '/' + task['name']
    shutil.rmtree(task['basepath'], ignore_errors=True)
    shutil.copytree(basepath + '/'+task['contest']['lang'] + "/template", task['basepath'])
    os.chdir(task['basepath'])
    # if(task['lang']=='java'): replaceJava(task)

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("-c", "--contest", help="current contest")
    parser.add_argument("-l", "--lang", help="lang")
    parser.add_argument("name", help="name of task")
    args = parser.parse_args()
    curt = {
        'contest': {
            "basepath": basepath + "/problems"
        },
        'name': args.name,
        'lang': 'cpp'
    }
    if args.lang:
        curt['lang'] = args.lang
    basepath+='/' + curt['lang']
    curt['contest']['basepath'] = basepath + "/problems"
    if args.contest:
        curt['contest']['basepath'] = basepath + "/" +  args.contest

    createTask(curt)
