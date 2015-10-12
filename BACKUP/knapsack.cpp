typedef struct {
        uint32_t bits;
        int value;
} solution;

void knapsack(int weight, int idx, solution *s)
{
        solution v1, v2;
        if (idx < 0) {
                s->bits = s->value = 0;
                return;
        }

        if (weight < item[idx].weight) {
                knapsack(weight, idx - 1, s);
                return;
         }
        knapsack(weight, idx - 1, &v1);
        knapsack(weight - item[idx].weight, idx - 1, &v2);

        v2.value += item[idx].value;
        v2.bits |= (1 << idx);
        *s = (v1.value >= v2.value) ? v1 : v2;
}