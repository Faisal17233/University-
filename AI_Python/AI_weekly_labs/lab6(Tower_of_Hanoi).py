def TowerOfHanoi(n, from_rod="A", to_rod="C", extra_rod="B"):
    global step, rod_a, rod_b, rod_c

    if n != 0:
        TowerOfHanoi(n - 1, from_rod, extra_rod, to_rod)

        print(f"Step {step}: Move disk {n} from Rod {from_rod} to Rod {to_rod}")
        step += 1

        if from_rod == "A":
            disk = rod_a.pop()
        elif from_rod == "B":
            disk = rod_b.pop()
        else:
            disk = rod_c.pop()

        if to_rod == "A":
            rod_a.append(disk)
        elif to_rod == "B":
            rod_b.append(disk)
        else:
            rod_c.append(disk)

        print(f"Rod A: {rod_a}\nRod B: {rod_b}\nRod C: {rod_c}\n")

        TowerOfHanoi(n - 1, extra_rod, to_rod, from_rod)


a = int(input("Enter number of disks: "))
rod_a = [i for i in range(a, 0, -1)]
rod_b, rod_c = [], []
print(f"Rod A: {rod_a}\nRod B: {rod_b}\nRod C: {rod_c}\n")

step = 1
TowerOfHanoi(a)