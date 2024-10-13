#IEEEXtreme 14.0 - mary fol
# Είσοδος: Αριθμός τεστ
n = int(input())
for i in range(n):
    T = list(map(int, input().rstrip().split()))  
# Ανάγνωση M, N, K
    J = []
    sum = 0
    for j in range(T[0]):  # Διαδικασία για κάθε όροφο
        m = int(input())
        sum += m
        J.append(m)
    
    J.sort()  # Ταξινόμηση για επιλογή των K κλεισιμάτων
     for k in range(T[2]):  
        sum += T[1] - 2 * J[k]
    print(sum)  
    # Εκτύπωση του μέγιστου αριθμού δωματίων με ρεύμα


