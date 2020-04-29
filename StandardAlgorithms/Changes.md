
#Version 20.0.2


- verify properties of operator < within example 'clamp'

- reduce very long verification times
  - add another assertion 'heap' to 'push_heap'
  - rewrite assertion 'update' of 'remove'
  - add assertion 'reorder' to empty else branch of 'shuffle'
  - add assertion 'unchanged' to empty else branch of 'remove_copy3'

- add examples find4 and find5 that show the equivalence of the contracts of
  find2 and find3

- add find_if_not

- add index of examples to tutorial

- add index of logic definitions to tutorial

- remove chapter on unique_copy due to its reliance on axioms

- adapt to stricter rule for labels in partial_sort (thanks to Virgile Prevosto)

- generate command names by python script

- improve admitted Coq proof of Reorder_Match

