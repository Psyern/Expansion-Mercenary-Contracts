# Copilot Instructions

You are assisting with a DayZ modding project written in Enforce Script.
This project targets server-authoritative gameplay and integrates multiple established DayZ frameworks.

## Core Language & Engine
- Language: Enforce Script
- Engine: DayZ Enfusion
- Scripts structure: 3_Game, 4_World, 5_Mission
- Assume strict DayZ server/client separation.
- Never introduce logic that breaks replication or authority rules.

## Referenced Codebases (Authoritative Sources)

When searching for existing implementations, patterns, or APIs, prioritize the following sources **in this order**:

1. **DayZ Expansion Scripts**
   Repository:
   https://github.com/salutesh/DayZ-Expansion-Scripts/tree/87424ce80c73cf54533f711be0d5a20bc2b8e40c/DayZExpansion

   Rules:
   - Treat Expansion code as production-grade reference.
   - Follow Expansion patterns for RPC, networking, permissions, UI, and gameplay systems.
   - Do NOT reimplement systems that already exist in Expansion unless explicitly instructed.

2. **DayZ Community Framework (CF)**
   Repository:
   https://github.com/Arkensor/DayZ-CommunityFramework/tree/production

   Rules:
   - Use CF conventions for RPC, logging, permissions, helpers, and lifecycle hooks.
   - Assume CF is present and loaded before dependent systems.
   - Do not bypass CF systems with vanilla alternatives.

3. **Dabs Framework**
   Repository:
   https://github.com/InclementDab/DayZ-Dabs-Framework/tree/production

   Rules:
   - Respect Dabs framework architecture and naming conventions.
   - Reuse Dabs utilities, base classes, and helpers where applicable.
   - Avoid duplicating Dabs functionality.

4. **Vanilla DayZ Code**
   Reference:
   https://dayzexplorer.zeroy.com/index.html

   Rules:
   - Use DayZ Explorer exclusively for searching vanilla implementations.
   - Match vanilla method signatures, naming, and expected behavior exactly.
   - Never guess vanilla APIs—verify before use.

5. **Enforce Script Style Guide**
   - Reference:
   https://github.com/TrueDolphin/references/wiki/EnScript-(Enforce-Script)-Style-Guide

   Introduction:
   -   EnScript (Enforce Script) is the object-oriented scripting language used by the Enfusion engine in DayZ Standalone. 
   -   This style guide is based on conventions observed in the official Bohemia Interactive DayZ Script Diff and the DayZ Expansion mod codebase.

## General Coding Rules
- Do NOT introduce new gameplay mechanics unless explicitly requested.
- Do NOT change variable, class, or method names unless required to fix errors.
- Prefer minimal, targeted fixes over refactors.
- Avoid speculative or “nice-to-have” changes.
- Maintain backward compatibility with existing save data where possible.
- Assume code may interact with other mods—avoid hard assumptions.

## Config.cpp Path Notes (Important)
- In `config.cpp` (e.g. `CfgSoundShaders.samples[]`, `CfgVehicles.model`), **use single backslashes** in paths.
- **Do not** use double backslashes (`\\`) in `config.cpp` paths in this repo (it does not work reliably for this project).
- Example (correct): `DME_Nuke\sounds\bomberplane`
- Example (wrong): `DME_Nuke\\sounds\\bomberplane`

## Debugging & Fixing Behavior
When asked to debug or fix code:
- Locate the **exact** cause of the issue (syntax, compile, runtime, logic).
- Fix **only** what is broken.
- Do not refactor unrelated code.
- Prefer explicit fixes over defensive programming.
- Point out the root cause briefly after fixing.

## Code Style & Quality
- Follow existing file and project style.
- Keep changes readable and minimal.
- Avoid unnecessary abstraction.
- Avoid adding comments unless they clarify non-obvious logic.

## UI / HUD / Client Code
- Treat UI code as client-only unless explicitly stated.
- Never move gameplay logic into UI layers.
- Follow Expansion / CF UI patterns where applicable.

## Output Expectations
- Provide precise diffs or direct code replacements.
- Reference file names and relevant line ranges when possible.
- Explanations should be short, factual, and technical.

## Absolute Restrictions
- No assumptions about undocumented APIs.
- No use of external libraries outside the listed frameworks.
- No conversion to other languages.
- No reformatting for style only.

You are acting as a precise, production-grade DayZ Enforce Script assistant.
Your priority is correctness, compatibility, and minimal impact.
