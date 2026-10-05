import random
import time


def print_status(player_hp, enemy_hp):
    """Displays health bars for both combatants."""
    p_bar = "█" * int(player_hp / 10) + "-" * (10 - int(player_hp / 10))
    e_bar = "█" * int(enemy_hp / 10) + "-" * (10 - int(enemy_hp / 10))
    print(f"\n[Hero's HP]:  [{p_bar}] {player_hp}/100")
    print(f"[Dragon's HP]: [{e_bar}] {enemy_hp}/100\n")


def main():
    print("=" * 45)
    print("Welcome to the 91-Line Text RPG Arena!")
    print("=" * 45)

    player_hp = 100
    enemy_hp = 100
    potions = 3

    while player_hp > 0 and enemy_hp > 0:
        print_status(player_hp, enemy_hp)

        # Player's Turn
        print("Choose your action:")
        print("1. Attack (Sword Strike)")
        print("2. Heal (Drink Potion)")
        print("3. Flee (Run away)")

        choice = input("> ")

        if choice == "1":
            damage = random.randint(12, 22)
            is_crit = random.random() < 0.20
            if is_crit:
                damage = int(damage * 1.5)
                print(f"✨ Critical hit! You strike the Dragon for {damage} damage!")
            else:
                print(f"⚔️ You slice the Dragon for {damage} damage.")
            enemy_hp = max(0, enemy_hp - damage)

        elif choice == "2":
            if potions > 0:
                heal = random.randint(25, 35)
                player_hp = min(100, player_hp + heal)
                potions -= 1
                print(f"🧪 You drank a potion and restored {heal} HP. ({potions} left)")
            else:
                print("❌ Out of potions! You wasted your turn searching your bag.")

        elif choice == "3":
            print("🏃 You coward! You fled the battle.")
            break
        else:
            print("🤔 You stumbled over your cape and missed your chance to act!")

        if enemy_hp <= 0:
            break

        # Enemy's Turn
        time.sleep(1)
        print("\n...The Dragon prepares its counterattack...")
        time.sleep(1)

        enemy_choice = random.random()
        if enemy_choice < 0.70:
            e_damage = random.randint(10, 18)
            print(f"🔥 The Dragon breathes fire at you for {e_damage} damage!")
            player_hp = max(0, player_hp - e_damage)
        else:
            print("💨 The Dragon roars out a warning, missing its attack!")

    # Battle Results
    print("\n" + "=" * 45)
    if player_hp <= 0 and enemy_hp <= 0:
        print("💥 The final blows traded took you both down. It's a draw!")
    elif player_hp > 0 and enemy_hp <= 0:
        print("🏆 Victory! The Dragon falls, and you are the champion!")
    elif player_hp <= 0 and enemy_hp > 0:
        print("💀 Defeat! You were turned to ash by the Dragon.")
    print("=" * 45)


if __name__ == "__main__":
    main()

