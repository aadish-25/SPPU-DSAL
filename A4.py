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
    for i in range(0, len(set3)):
        print(i, " ")
    return

def createSet(set3):
    n = int(input("Enter number of elements of the set 2 : "))
    for i in range(n):
        ele = int(input())
        insertElement(ele, set3)
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
            insertElement(addNum)

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
            print("Intersection operation selected.")
        elif choice == "8":
            print("Union operation selected.")
        elif choice == "9":
            print("Difference operation selected.")
        elif choice == "10":
            print("Subset check selected.")
        elif choice == "0":
            print("Exiting program.")
            break
        else:
            print("Invalid choice. Please try again.")

main()
