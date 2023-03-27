from dataclasses import dataclass


class Chart:
    def __init__(self, name, children):
        self.name = name
        self.children = children

# return a chart object
def read_tree(line):
    pieces = line.split(" ")
    # some kind of stack-based read in??


# idk... this problem is just about dealing with ugly input
def compare_charts(c1, c2):
    return True