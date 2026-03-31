seats = [
    [1, 0, 1, 1],
    [0, 1, 1, 0],
    [1, 1, 0, 0]
]

row_number = 1
occupied_seats = 0
unoccupied_seats = 0

for row in seats:
    occupied = 0
    unoccupied = 0
    print("Row", row_number, ":"  , end=" ")
    
    for seat in row:
        print(seat, end=" ")
        
        if seat == 1:
            occupied += 1
            occupied_seats += 1

        else:
            unoccupied += 1
            unoccupied_seats += 1
        
            
    print()
    row_number += 1
    print("Row", row_number - 1, "has", occupied, "occupied seats and", unoccupied, "unoccupied seats.")
    
print("Total occupied seats:", occupied_seats)
print("Total unoccupied seats:", unoccupied_seats)
