#!/usr/bin/python3
import argparse
import os
import shutil
import task

basepath = "/home/oleg/coding/olimp"
parser = argparse.ArgumentParser()
parser.add_argument("-n", "--number", type=int, help="number of problems")
parser.add_argument("-cf", action="store_true")
parser.add_argument("-l", "--lang",
                    choices=('cpp', 'java'))
parser.add_argument("name", help="name of contest")
args = parser.parse_args()

contest = {
    "name": args.name,
    "n": 5,
    "lang": "cpp"
}
if args.cf:
    contest["name"] = "Cf" + str(args.name)
if args.number:
    contest["n"] = args.number
if args.lang:
    contest["lang"] = args.lang

contest["basepath"] = basepath +"/" + contest["lang"] \
                        + "/" + contest["name"]
shutil.rmtree(contest["basepath"], ignore_errors=True)
os.makedirs(contest["basepath"])
for i in range(contest['n']):
    curt = {
        "contest": contest,
        "name": contest['name'] + chr(ord('A') + i)
    }
    task.createTask(curt)
