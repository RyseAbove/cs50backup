# Simulate a sports tournament

import csv
import sys
import random

# Number of simluations to run
N = 1000


def main():

    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    teams = []

    # file = open(sys.argv[1])
    with open(sys.argv[1], newline='') as file:
        reader = csv.DictReader(file)
        for row in reader:
            # copy csv to file
            teams.append(row)

    for element in teams:
        element['rating'] = int(element['rating'])

    counts = {}

    for element in teams:
        counts[element['team']] = 0

    for i in range(N):
        winning_team = simulate_tournament(teams)
        counts[winning_team] += 1
        # store winning team name in a variable
        # add 1 to counts of winning team

    # Print each team's chances of winning, according to simulation
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    # number of teams will always be a power of 2
    # print out one winner
    while len(teams) > 1:
        teams = simulate_round(teams)
    return teams[0]['team']

main()