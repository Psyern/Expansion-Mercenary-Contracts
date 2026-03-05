# DME_EMC – Expansion Mercenary Contracts

Server-authoritative mercenary hire scaffold for **DayZ Expansion** environments.

This mod adds a simple, config-driven “hire mercenary” flow and integrates with **Expansion Market** so mercenaries can be purchased like trader items.

## Features

- Server-authoritative hire requests (client sends only the selection).
- Auto-created config JSON under:
  - `$profile:\DeadmansEcho\ExpansionMercenaryContracts\ExpansionMercenaryContracts.json`
- Expansion Market integration:
  - Buy a fake Market item like `Mercenary1` … `Mercenary10` to hire a mercenary.
  - **One purchase = exactly one hire** (count is ignored).
- Minimal fake item definitions are included so Expansion Market can resolve the class names:
  - `Mercenary1` … `Mercenary10` (CfgVehicles, `Inventory_Base`)

## Installation

1. Add the mod to your server and client mod lists.
2. Start the server once to auto-create the config.
3. Edit the config JSON as needed.

## Configuration

File:
- `$profile:\DeadmansEcho\ExpansionMercenaryContracts\ExpansionMercenaryContracts.json`

Schema:
- `Version` (int)
- `MaxMercPerPlayer` (int)
- `Mercenaries[]`:
  - `Loadout` (string)
  - `Payment` (int) – currently not used (Market is the single payment source)
  - `Cost` (int) – currently not used (Market item price is used)
  - `Cooldown` (int seconds)

Defaults include:
- `BanditLoadout`
- `NBCLoadout`

## Expansion Market Setup

Add items to any category JSON (`profiles/ExpansionMod/Market/*.json`) like:

- `Mercenary1` (maps to merc index 0)
- `Mercenary2` (maps to merc index 1)
- …
- `Mercenary10` (maps to merc index 9)

Example item entry:

- `ClassName`: `Mercenary1`
- `MaxPriceThreshold` / `MinPriceThreshold`: set your hire price
- Stock/quantity fields can be set like any other market item.

### Mapping

- `Mercenary1` → `Mercenaries[0]`
- `Mercenary2` → `Mercenaries[1]`
- ...
- `Mercenary10` → `Mercenaries[9]`

## Notes / Current Stub Areas

This repository is a scaffold. The following are intentionally minimal and can be expanded later:

- Payment integration in `EMC_MercenaryService.TryTakePayment()` (currently returns true)
  - **Recommended setup**: use Expansion Market price as the only payment source.
- AI follow/guard ownership integration and applying Expansion loadouts.

## Script Layout

- `DME_EMC/scripts/3_Game`: config model/loader, constants, logging, RPC ids
- `DME_EMC/scripts/4_World`: service logic, player runtime data, market integration patch
- `DME_EMC/scripts/5_Mission`: client RPC/UI scaffolding (not required if using Market)

## License

Project-specific; add your license text here.
