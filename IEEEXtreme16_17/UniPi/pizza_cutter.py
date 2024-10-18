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

test_cases = get_number()

def cut_pizzas(n_pizzas):
    for i in range(n_pizzas):
        n_cuts = get_number()

        cuts = set()
        for _ in range(n_cuts):
            cuts.add(get_number()%180) # Θέλουμε μόνο θετικές μοίρες και μεταξύ 0<=θ<180

        slices = 1 # Αριθμός κομματιών
        for cut in cuts:
            # Όταν η πιτσα δεν έχει κοπεί ακόμα τότε οποιαδήποτε κοπή δημιουργεί 2 κομμάτια
            if slices == 1:
                slices += 1
            # Όταν έχει ήδη κοπεί η πίτσα, τότε οποιαδήποτε κοπή δημιουργεί 2 έξτρα κομμάτια
            else:
                slices += 2
        print(slices)

cut_pizzas(test_cases)