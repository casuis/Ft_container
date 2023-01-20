# MAP

### LIEN :
	
* pdf : file:///mnt/nfs/homes/asimon/Downloads/introduction_algo%20(1).pdf

### RBT 
* https://www.youtube.com/playlist?list=PLpPXw4zFa0uKKhaSz87IowJnOTzh9tiBk

### rebalance deletion:
* https://www.geeksforgeeks.org/deletion-in-red-black-tree/
* https://medium.com/analytics-vidhya/deletion-in-red-black-rb-tree-92301e1474ea
* https://www.codesdope.com/course/data-structures-red-black-trees-deletion/



////////////////////////////////////////////////////////////////////////////////


# RBT RULES

* Ne peut pas avoir deux nodes rouges consecutifs

* Root est toujours black

* Nulls est black

* Meme nombre de black node sur chacunes des branches

* Un nouveau node est toujours rouge

## ROTATIONS

* Black aunt: => rotate

* Red aunt: => color flip

### LEFT ROTATION

* Right sub child --> rotation on gp
	=> gp become left of parent/ parent become gp / left of parent become right of gp

### RIGHT ROTATION

* Left subchild --> rotation on gp
	=> gp become right of parent/ parent become gp / right of parent 


## DELETION

### RULES

_Violation if their is **double black**_ 
> double black:  When a black node is deleted and replaced by a black child, the child is marked as double black

* If sibling s is black and at least one of sibling’s children is red, perform rotation(s)

# MAP ITERATOR

_creation d'un node breack point:_
* parent = node precedant
* sentinel = true
* left = NULL
* right = NULL