import random

def generate_unique_numbers(count, min_value, max_value):
    """
    Génère une chaîne de nombres uniques aléatoires, séparés par des espaces.

    :param count: Nombre de nombres à générer.
    :param min_value: Valeur minimale des nombres.
    :param max_value: Valeur maximale des nombres.
    :return: Une chaîne contenant les nombres séparés par des espaces.
    """
    if count > (max_value - min_value + 1):
        raise ValueError("Impossible de générer autant de nombres uniques dans cet intervalle.")
    
    numbers = random.sample(range(min_value, max_value + 1), count)
    return " ".join(map(str, numbers))

# Exemple d'utilisation
try:
    result = generate_unique_numbers(500, 1, 2147483647)  # Génère 10 nombres uniques entre 1 et 100
    print(result)
except ValueError as e:
    print(e)
