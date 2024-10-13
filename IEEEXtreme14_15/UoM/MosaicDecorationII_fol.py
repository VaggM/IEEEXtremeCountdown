import math

# Βήμα 1: Ανάγνωση και επεξεργασία εισόδου
L = list(map(int, input().rstrip().split())) 
W, H, A, B, M, C = L

# Βήμα 2: Υπολογισμός αριθμού πλακιδίων
rowtiles = math.ceil(W / A)
coltiles = math.ceil(H / B)
ntiles = rowtiles * coltiles

# Βήμα 3: Υπολογισμός επιπλέον χώρου και κοψιμάτων
rowplus = rowtiles * A - W
colplus = coltiles * B - H
cuttinginch = 0

# Βήμα 4: Υπολογισμός κόστους κοψίματος
if rowplus != 0:
    cuttinginch += H
if colplus != 0:
    cuttinginch += W

# Βήμα 5: Υπολογισμός συνολικού κόστους (πλακάκια + κοψίματα)
price = math.ceil(ntiles / 10) * M + cuttinginch * C

# Βήμα 6: Εκτύπωση συνολικού κόστους
print(price)
