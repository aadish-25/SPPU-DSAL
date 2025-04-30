# To create ADT that implement the "set" concept.
# a. Add (newElement) -Place a value into the set
# b. Remove (element) Remove the value
# c. Contains (element) Return true if element is in collection
# d. Size () Return number of values in collection Iterator () Return an iterator used to loop
# over collection
# e. Intersection of two sets
# f. Union of two sets
# g. Difference between two sets
# h. Subset


set1 = []
set2 = []

def insertElement(n, set3):
    if n not in set3:
        set3.append(n)
    return

def removeElement(n):
    if n in set1:
        set1.remove(n)
    else:
        print("Number does not exist in the set")
    return

def containElement(n):
    if n in set1:
        return True
    else:
        return False

def checkSize(set3):
    print("The size of the set is", len(set3))
    return

def iterateSet(set3):
    for ele in set3:
        print(ele)
    # return iter(set3)
    return

def createSet(set3):
    n = int(input("Enter number of elements of the set 2 : "))
    for i in range(n):
        ele = int(input())
        insertElement(ele, set3)
    return

def intersectSet(set1, set2):
    intersect = []
    for ele in set1:
        if ele in set2:
            intersect.append(ele)
    return intersect

def unionSet(set1, set2):
    union = []
    for ele in set1:
        union.append(ele)
    for ele in set2:
        if ele not in union:
            union.append(ele)
    return union

def differenceSet(set1, set2):
    # set1 - set2
    difference = []
    for ele in set1:
        if ele not in set2:
            difference.append(ele)
    return difference

def checkSubset(set1, set2):
    if(set1 == set2):
        print("Both sets are subsets of each other")
        return
    else:
        count1 = 0
        count2 = 0
        for ele in set1:
            if ele in set2:
                count1+=1
        if len(set2) == count1:
            print("Set 2 is a subset of Set 1")
            return

        for ele in set2:
            if ele in set1:
                count2+=1
        if len(set1) == count2:
            print("Set 1 is a subset of Set 2")
            return
        
    print("No set is a subset of each other")
    return

def main():
    while True:
        print("\nSet Operations Menu:")
        print("1. Add an element to the set")
        print("2. Remove an element from the set")
        print("3. Check if an element exists in the set")
        print("4. Get the size of the set")
        print("5. Display all elements in the set")
        print("6. Add elements to set2")
        print("7. Find intersection with another set")
        print("8. Find union with another set")
        print("9. Find difference with another set")
        print("10. Check if current set is a subset of another set")
        print("0. Exit")

        choice = input("Enter your choice: ")

        if choice == "1":
            addNum = int(input("Enter the number to add : "))
            insertElement(addNum, set1)

        elif choice == "2":
            removeNum = int(input("Enter the number to remove : "))
            removeElement(removeNum)

        elif choice == "3":
            checkNum = int(input("Enter element to be checked if the set contains it"))
            contains = containElement(checkNum)

            if contains == True:
                print("Number exists in the set")
            else:
                print("Number does not exist in the set")

        elif choice == "4":
            checkSize(set1)
            
        elif choice == "5":
            print("Executing iterator")
            iterateSet(set1)

        elif choice == "6":
            createSet(set2)

        elif choice == "7":
            intersectingElements = intersectSet(set1, set2)
            print(intersectingElements)

        elif choice == "8":
            unionElements = unionSet(set1, set2)
            print(unionElements)

        elif choice == "9":
            print("Difference between two sets : ")
            print("1. A - B")
            print("2. B - A")
            choice = int(input())

            if(choice == 1):
                print("The difference A - B is : ",differenceSet(set1, set2))
            elif(choice == 2):
                print("The difference B - A is : ", differenceSet(set2, set1))
            else:
                print("Invalid Choice")
                continue

        elif choice == "10":
            checkSubset(set1, set2)

        elif choice == "0":
            print("Exiting program.")
            break

        else:
            print("Invalid choice. Please try again.")

main()
