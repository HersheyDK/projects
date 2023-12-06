import random

MAX_LINES = 3
MAX_BET = 100
MIN_BET = 1

ROWS = 3
COLS = 3

symbol_count = {
    "A": 2,
    "B": 4,
    "C": 6,
    "D": 8
}

symbol_value = {
    "A": 5,
    "B": 4,
    "C": 3,
    "D": 2
}

def check_win(columns, lines, bet, values):
    winnings = 0
    winning_lines = []
    for line in range(lines):
        symbol = columns[0][line]
        for column in columns:
            symbol_to_check = column[line]
            if symbol != symbol_to_check:
                break
        else:
            winnings += values[symbol] * bet
            winning_lines.append(line + 1)

    return winnings, winning_lines




def spin(rows, cols, symbols):
    all_symbols = []
    for symbol, symbol_count in symbols.items():
        for i in range(symbol_count):
            all_symbols.append(symbol)

    columns = []
    for col in range(cols):
        column = []
        curr_symbols = all_symbols[:]
        for row in range(rows):
            value = random.choice(curr_symbols)
            curr_symbols.remove(value)
            column.append(value)

        columns.append(column)
    
    return columns

def print_machine(columns):
    for row in range(len(columns[0])):
        for i, column in enumerate(columns):
            if i != len(columns) - 1:
                print(column[row], end = "|")
            else:
                print(column[row], end = "")

        print()

def deposit():
    while True:
        amount = input("How much would you like to deposit? ")
        if amount.isdigit():
            amount = int(amount)
            if amount > 0:
                break
            else:
                print("Please enter a positive number.")
        else:
            print("Please enter a number.")
    return amount

def numLines():
    while True:
        lines = input("How many lines between 1-" + str(MAX_LINES) + " would you like?  ")
        if lines.isdigit():
            lines = int(lines)
            if lines > 0 and lines <= MAX_LINES:
                break
            else:
                print("Please enter a positive number between 1-3.")
        else:
            print("Please enter a number.")
    return lines

def get_bet():
    while True:
        bet = input("How much would you like bet? ")
        if bet.isdigit():
            bet = int(bet)
            if bet >= MIN_BET and bet <= MAX_BET:
                break
            else:
                print(f"Please enter a positive number between ${MIN_BET} and ${MAX_BET}")
        else:
            print("Please enter a number.")
    return bet

def main():
    balance = deposit()
    lines = numLines()
    while True:
        bet = get_bet()
        total_bet = bet * lines

        if total_bet > balance:
            print(f"You do not have enough to bet that amount. Current Balance: {balance}. Your bet: {total_bet}")
        else:
            break

    print(f"You're betting ${total_bet} on {lines} lines. Total bet: {total_bet}")

    slots = spin(ROWS, COLS, symbol_count)
    print_machine(slots)
    winnings, winning_lines = check_win(slots, lines, bet, symbol_value)
    if winnings == 0:
        print("You lost")
    else: 
        print(f"You won ${winnings}")
        print(f"You won on lines: ",  *winning_lines)

main()

