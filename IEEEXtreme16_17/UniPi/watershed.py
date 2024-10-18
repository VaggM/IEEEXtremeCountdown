# a simple parser for python. use get_number() and get_word() to read
def parser():
    while 1:
        data = list(input().split(' '))
        for number in data:
            if len(number) > 0:
                yield(number)   

input_parser = parser()

def get_word():
    global input_parser
    return next(input_parser)

def get_number():
    data = get_word()
    try:
        return int(data)
    except ValueError:
        return float(data)

# Γραμμες και Κολώνες
n,m = get_number(), get_number()
sort_grid = [] # Μήτρα/Λίστα με τα ύψη και τις συντεταγμένες
access_grid = dict() # Hash table με τα ύψη, θα μπορούσαμε να κάνουμε και Μήτρα/ 2-Διάστατο Πίνακα
drain_grid = dict() # Hash table με τα λίτρα νερού
# Create sort grid and access grid
for i in range(n):
    for j in range(m):
        height=get_number()
        sort_grid.append((i,j,height))
        access_grid[f'{i},{j}']=height
        drain_grid[f'{i},{j}']=1

# Ταξινόμηση του sort_grid με βάση το ύψος
sort_grid.sort(key=lambda x: x[2], reverse=True) # Φθείνουσα -> reverse=True

# Για κάθε κελί, βγάλε το νερό στα γύρω κελιά
for cell in sort_grid:
    x,y,height = cell
    n_drains = 0 # Αριθμός χαμηλότερων υψών

    # Υπολογίζουμε πόσοι έχουν χαμηλότερο ύψος
    if x+1 < n and access_grid[f'{x+1},{y}'] < height:
        n_drains += 1
    if x-1 >= 0 and access_grid[f'{x-1},{y}'] < height:
        n_drains += 1
    if y+1 < m and access_grid[f'{x},{y+1}'] < height:
        n_drains += 1
    if y-1 >= 0 and access_grid[f'{x},{y-1}'] < height:
        n_drains += 1
    
    # Επίπεδο νερού στο κελί
    current_drain = drain_grid[f'{x},{y}']
    # Αποσύρουμε το νερό στα γειτονικά χαμηλότερα κελιά
    if x+1 < n and access_grid[f'{x+1},{y}'] < height:
        drain_grid[f'{x+1},{y}'] += current_drain/n_drains
    if x-1 >= 0 and access_grid[f'{x-1},{y}'] < height:
        drain_grid[f'{x-1},{y}'] += current_drain/n_drains
    if y+1 < m and access_grid[f'{x},{y+1}'] < height:
        drain_grid[f'{x},{y+1}'] += current_drain/n_drains
    if y-1 >= 0 and access_grid[f'{x},{y-1}'] < height:
        drain_grid[f'{x},{y-1}'] += current_drain/n_drains

max_drain = max(drain_grid.values())
print(max_drain)
