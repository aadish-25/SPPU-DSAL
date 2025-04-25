def linear_probing(arr, n, name, tele):
    hashkey = tele % n
    i = 0

    while arr[hashkey][0] != "" and i < n:
        i += 1
        hashkey = (hashkey + 1) % n

    if i == n:
        print("Database is full, cannot add")
        return

    arr[hashkey][0] = name
    arr[hashkey][1] = str(tele)
    print(f"Client entry added, no of comparisons required: {i}")

def double_hashing(arr, n, name, tele):
    primary_hashkey = tele % n
    secondary_hashkey = 7 - (tele % 7)
    i = 0

    newhashkey = primary_hashkey
    while arr[newhashkey][0] != "":
        i += 1
        newhashkey = (primary_hashkey + (i * secondary_hashkey)) % n
        
    if i == n:
        print("Database is full, cannot add")
        return

    arr[newhashkey][0] = name
    arr[newhashkey][1] = str(tele)
    print(f"Client entry added, no of comparisons required: {i}")

def add_to_hash(arr, n):
    name = input("Enter client name: ")
    tele = int(input("Enter client telephone number: "))

    hashkey = tele % n

    if arr[hashkey][0] == "":
        arr[hashkey][0] = name
        arr[hashkey][1] = str(tele)
        print("Client entry added, no of comparisons required: 0")
    else:
        method = int(input("Collision occurred!\nSelect collision handling method:\n1. Linear Probing\n2. Double Hashing\n"))
        if method == 1:
            linear_probing(arr, n, name, tele)
        elif method == 2:
            double_hashing(arr, n, name, tele)
        else:
            print("Invalid method, phone number not added")

def search_hash(arr, n):
    searchnum = int(input("Enter the number to search: "))
    hashkey = searchnum % n
    comparisons = 0

    while arr[hashkey][1] != "":
        comparisons += 1

        if int(arr[hashkey][1]) == searchnum:
            print(f"Number found, belongs to {arr[hashkey][0]}")
            print(f"Number of comparisons required: {comparisons}")
            return

        hashkey = (hashkey + 1) % n

    print("Number not found")

def display_database(arr, n):
    print("\n-------- Telephone Book --------")
    print(f"{'Index':<10}{'Name':<20}{'Phone':<15}")
    for i in range(n):
        if arr[i][0] != "":
            print(f"{i:<10}{arr[i][0]:<20}{arr[i][1]:<15}")
    print("-------------------------------")

def main():
    n = int(input("Enter total number of clients: "))
    arr = []
    for _ in range(n):
        arr.append(["", ""])

    while True:
        print("\n-------------------MENU-----------------")
        print("1. Add phone number")
        print("2. Search phone number")
        print("3. Display database")
        print("4. Exit")
        choice = int(input("Enter your choice: "))

        if choice == 1:
            add_to_hash(arr, n)
        elif choice == 2:
            search_hash(arr, n)
        elif choice == 3:
            display_database(arr, n)
        elif choice == 4:
            print("Exiting program...")
            break
        else:
            print("Invalid choice, try again.")


main()