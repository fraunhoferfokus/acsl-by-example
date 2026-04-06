
# Changes

This file documents user-visible changes and known limitations of released
snapshots of *ACSL by Example*.  It is intended to complement the stable overview
provided in `README.md`.

---

## Version 32.0.3  
(Targeting Frama-C 32.0 “Germanium”)

### Improvements

- **Refactored `\Stack` example**  
  Shift from a procedure-oriented workflow to a structured, multi-level methodology emphasizing observational equality, well-definedness, and modular reasoning.  
  - Introduced a clear three-level separation: abstract axioms --- logical specifications --- implementation  
  - Strengthened role of observational equality (including equivalence properties)  
  - Added systematic well-definedness witnesses, separated from axiom verification  
  - Reorganized verification flow: operations → axioms → well-definedness  
  - Simplified witness specifications (removed low-level clauses for readability)  
  - Improved modularization of the logical interface and separation of representation vs.\ specification  

- **Removed axiomatic blocks** in logic definitions  

- **Revised `\Equal` (third version)**  
  Now an explicit expansion with fully written-out universal quantification  

- **Adjusted `\Reverse` predicate**  
  Second range now specified via one-past-the-end index  

- **Fixed bug in `\Rotate` (first version)**  
  Corrected argument usage  

- **Simplified `\makepair`**  

- **Added figures**  
  Supporting `\Reverse`, `\reversecopy`, and `\reverse`  

- **Improved description of `\rotatei`**  
  Clarified implementation and verification  

- **Expanded specification of `\clamp`**  

- **Corrected misplaced LaTeX labels** for ACSL listings  
