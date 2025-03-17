def find_parent(x):
    if x == 1:
        return None  # Root process has no parent
    
    process = 1  # Start from process 1
    count = 1  # Process 1 spawns 1 child
    while count + process < x:
        process += 1
        count += process
    
    return process

# Example usage:
x = int(input("Enter process number: "))
parent = find_parent(x)
print(f"The parent of process {x} is: {parent}")
