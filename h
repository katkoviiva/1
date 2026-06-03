To implement elf immunity to rotten food in NetHack (either as a custom variant or a code patch), you need to modify the eating mechanics in eat.c and the player race definitions in role.c to prevent elves from getting sick from tainted meals.Step 1: Define Elf Immunity in role.cIn NetHack, intrinsic properties are typically granted through race or role. You need to assign an immunity property (e.g., SICK_RES or a custom race property Elven_resistance) to the Elven race.Locate your race definitions in src/role.c.Find the entry for Elves (e.g., PM_ELF or urace struct).Update the racial intrinsics to include sickness/rot resistance.c/* Example of assigning intrinsics in urace */
static const struct Race race_list[] = {
    ...
    { "Elf", &mons[PM_ELF], ... , SICK_RES, ... },
    ...
};
Käytä koodia harkiten.Step 2: Modify the Rot/Sick Check in src/eat.cThe game checks whether a food item is rotten and applies the vomit/sickness effects. You will need to wrap these checks with a conditional to ensure your elves are spared.Open src/eat.c and locate the eatfood function (or get_food_effects).Find the code blocks that handle food poisoning, choking, or vomiting when the player eats a "tainted" or "rotten" item.Wrap the negative effect in a conditional statement checking for the elf race (e.g., Race_if(PM_ELF)) so it skips the illness.c/* Conceptual patch for eat.c */
if (is_rotten(food_item)) {
    if (Race_if(PM_ELF)) {
        You("happily consume the seasoned forest meal. It tastes delicious to your elven palate.");
        /* Award standard nutrition here */
    } else {
        You("feel nauseated!");
        make_vomiting((long)rn2(20)+10, TRUE);
    }
}
Käytä koodia harkiten.Step 3: Prevent Rotten Messages for ElvesIf elves can eat rotting meat with no ill effects, you should also adjust the in-game messaging so they do not receive warnings like "You feel sick!" when eating carrion.In the same file (src/eat.c), add an if (Race_if(PM_ELF)) check to the message handling so the flavor text is appropriately tailored to their racial immunity.If you'd like, I can:Pinpoint exact line numbers in src/eat.c for your specific NetHack version.Show you how to implement Elven vegetarian/cannibal restrictions along with this immunity.Explain how to compile and test your C code locally in Jyväskylä.Let me know which specific version of NetHack you are modifying.