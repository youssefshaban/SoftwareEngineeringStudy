def hashFan(n,i):
    index = int(i % n)
    return index




def insert (arr,value):
    index = hashFan(len(arr),value)
    if arr[index]== None:
        arr[index]=value
    else :
        looper = 0
        for i in range(len(arr)):
            if looper != 0 :
                if i == index:
                    return

            if i == len(arr):
                if looper == 0:
                    i=0
                    looper=1
            if (index + i) <= (len(arr)-1):
                if  arr[index+i]== None:
                    arr[index+i] = value
                    return

def search (arr,kye):
    index = hashFan(len(arr),kye)
    if arr[index]==kye:
        print(f"{kye} found ")
        return index
    else :
        looper = 0
        for i in range(len(arr)):
            if looper != 0:
                if i == index:
                    print(f"{kye} not found ")
                    return None
            if (index+i) <= (len(arr)-1):

                if arr[index + i] == kye:
                    print(f"{kye} found ")
                    return index
            if i >= len(arr):
                if looper == 0:
                    i = 0
                    looper = 1
        print(f"{kye} not found ")
        return None

def delete(arr,value):
    index = search(arr,value)
    print(index)
    if index != None :
        arr[index]=None
        print(f"{value} deleted")
    else:
        print(f"{value} not found")

def custom():
    arr = [None] * 23

    insert(arr, 4)
    insert(arr, 13)
    insert(arr, 15)
    insert(arr, 23)
    insert(arr, 7)
    insert(arr, 89)
    insert(arr, 53)
    insert(arr, 86)
    insert(arr, 24)
    insert(arr, 41)
    insert(arr, 113)
    insert(arr, 115)
    insert(arr, 213)
    insert(arr, 71)
    insert(arr, 189)
    insert(arr, 513)
    insert(arr, 861)
    insert(arr, 214)
    insert(arr, 132)
    insert(arr, 611)
    insert(arr, 143)
    insert(arr, 6121)
    insert(arr, 5)
    insert(arr, 6)
    insert(arr, 8)
    insert(arr, 9)


    search(arr, 4)
    search(arr, 13)
    search(arr, 15)
    search(arr, 23)
    search(arr, 7)
    search(arr, 89)
    search(arr, 53)
    search(arr, 86)
    search(arr, 24)
    search(arr, 41)
    search(arr, 113)
    search(arr, 115)
    search(arr, 213)
    search(arr, 71)
    search(arr, 189)
    search(arr, 513)
    search(arr, 861)
    search(arr, 214)
    search(arr, 132)
    search(arr, 611)
    search(arr, 143)
    search(arr, 6121)
    search(arr, 5)
    search(arr, 6)
    search(arr, 8)
    search(arr, 9)

    delete(arr,611)
    insert(arr, 9)
    search(arr, 9)
    delete(arr,612)
    print(arr)


if __name__ == "__main__":
    custom()
