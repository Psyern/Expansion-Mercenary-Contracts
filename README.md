# Expansion-Mercenary-Contracts

Server-authoritative mercenary contract prototype for DayZ Expansion-style mods.

## Implemented architecture

- Server-only gameplay decision path for hire requests.
- Auto-create config folder + JSON under:
  - `$profile:\DeadmansEcho\ExpansionMercenaryContracts\ExpansionMercenaryContracts.json`
- Config schema:
  - `Version`
  - `MaxMercPerPlayer`
  - `Mercenaries[]` with `Loadout`, `Payment`, `Cost`, `Cooldown`
- Client UI only sends `mercIndex` hire request.
- Server validates max-merc, cooldown, payment adapter, and spawn.

## Script layout

- `Scripts/3_Game`: constants, log, config model/loader, RPC ids.
- `Scripts/4_World`: broker NPC stub, player runtime data, mercenary service.
- `Scripts/5_Mission`: mission hooks and UI scaffolding.

## Notes

This is an integration scaffold with explicit adapter stubs for Expansion systems:

- Currency/Market payment integration.
- Hardline reputation payment integration.
- Expansion AI ownership/follow/guard order integration.
- Loadout application integration.
