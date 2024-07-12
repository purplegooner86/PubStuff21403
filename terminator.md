## Keybindings

- split_horiz (change to Ctrl+Down)
- split_vert (change to Ctrl+Right)
- scaled_zooom (unbind it)
- toggle_zoom (change to Ctrl+Shift+Z)
- edit_tab_title (change to ctrl+alt+,)
- Add ctrl+alt+number to all of the tab changers

<br />

## Customizing Tab Header Size

Terminator is a GTK-3 application. gtk-3 styles are described with pure CSS. You can overwrite the styles for any GTK-3 application by creating the file `~/.config/gtk-3.0/gtk.css`  

Tabs:
```css
.terminator-terminal-window notebook tab {
	background-color: #282C34;
	padding: 0.0em;
	border: 0;
	border-color: #444;
	border-style: solid;
	border-width: 1px;
}

.terminator-terminal-window notebook tab:checked {
	background-color: #222;
	background-image: none;
}

.terminator-terminal-window notebook tab:checked label {
	color: #56B6C2;
}
```

<br />

## Goto configuration

terminator holds a lot of its configs in `~/.config/terminator/config`

```sh
[global_config]
  always_split_with_profile = True
  handle_size = 1
  scroll_tabbar = True
  inactive_color_offset = 0.8048780487804879
[keybindings]
  split_horiz = <Primary>Down
  split_vert = <Primary>Right
  toggle_zoom = <Primary><Shift>z
  scaled_zoom = None
  switch_to_tab_1 = <Primary><Alt>1
  switch_to_tab_2 = <Primary><Alt>2
  switch_to_tab_3 = <Primary><Alt>3
  switch_to_tab_4 = <Primary><Alt>4
  switch_to_tab_5 = <Primary><Alt>5
  switch_to_tab_6 = <Primary><Alt>6
  switch_to_tab_7 = <Primary><Alt>7
  switch_to_tab_8 = <Primary><Alt>8
  switch_to_tab_9 = <Primary><Alt>9
  edit_tab_title = <Primary><Alt>comma
  layout_launcher = ""
[profiles]
  [[default]]
    background_color = "#282c34"
    cursor_shape = ibeam
    cursor_color = "#aaaaaa"
    foreground_color = "#eeeeec"
    show_titlebar = False
    scrollbar_position = hidden
    scrollback_lines = 1000
    palette = "#282c34:#e06c75:#98c379:#e5c07b:#61afef:#c678dd:#56b6c2:#dcdfe4:#5a6374:#e06c75:#98c379:#e5c07b:#61afef:#c678dd:#56b6c2:#dcdfe4"
    use_custom_command = True
    custom_command = zsh
  [[AppleClassic]]
    background_color = "#2c2b2b"
    cursor_shape = ibeam
    cursor_color = "#aaaaaa"
    foreground_color = "#d5a200"
    show_titlebar = False
    scrollbar_position = hidden
    palette = "#000000:#c91b00:#00c200:#c7c400:#61afef:#ca30c7:#00c5c7:#c7c7c7:#686868:#ff6e67:#5ffa68:#fffc67:#61afef:#ff77ff:#60fdff:#ffffff"
    use_custom_command = True
    custom_command = zsh
  [[ayu]]
    background_color = "#0f1419"
    cursor_shape = ibeam
    cursor_color = "#f29718"
    foreground_color = "#e6e1cf"
    show_titlebar = False
    scrollbar_position = hidden
    palette = "#000000:#ff3333:#b8cc52:#e7c547:#36a3d9:#f07178:#95e6cb:#ffffff:#323232:#ff6565:#eafe84:#fff779:#68d5ff:#ffa3aa:#c7fffd:#ffffff"
    use_custom_command = True
    custom_command = zsh
  [[cyberpunk]]
    background_color = "#332a57"
    cursor_shape = ibeam
    cursor_color = "#21f6bc"
    foreground_color = "#e5e5e5"
    show_titlebar = False
    scrollbar_position = hidden
    palette = "#000000:#ff7092:#00fbac:#fffa6a:#00bfff:#df95ff:#86cbfe:#ffffff:#000000:#ff8aa4:#21f6bc:#fff787:#1bccfd:#e6aefe:#99d6fc:#ffffff"
    use_custom_command = True
    custom_command = zsh
  [[cyberpunkNew]]
    background_color = "#272932"
    cursor_shape = ibeam
    cursor_color = "#f29718"
    foreground_color = "#E455AE"
    show_titlebar = False
    scrollbar_position = hidden
    palette = "#272932:#710000:#1AC5B0:#FDF500:#9381FF:#742D8B:#00D0DB:#D1C5C0:#7b8097:#C71515:#40FFE9:#fff955:#37EBF3:#CB1DCD:#37EBF3:#C1DEFF"
    use_custom_command = True
    custom_command = zsh
  [[Django2]]
    background_color = "#051f14"
    cursor_shape = ibeam
    cursor_color = "#ffcc00"
    foreground_color = "#dadedc"
    show_titlebar = False
    scrollbar_position = hidden
    palette = "#000000:#fd6209:#41a83e:#ffe862:#245032:#c678dd:#9df39f:#ffffff:#323232:#ff943b:#73da70:#ffff94:#568264:#c678dd:#cfffd1:#ffffff"
    use_custom_command = True
    custom_command = zsh
  [[Pandora]]
    background_color = "#141e43"
    cursor_shape = ibeam
    cursor_color = "#43d58e"
    foreground_color = "#e1e1e1"
    show_titlebar = False
    scrollbar_position = hidden
    palette = "#000000:#ff4242:#74af68:#ffad29:#338f86:#9414e6:#23d7d7:#e2e2e2:#3f5648:#ff3242:#74cd68:#ffb929:#23d7d7:#ff37ff:#00ede1:#ffffff"
    use_custom_command = True
    custom_command = zsh
[layouts]
  [[default]]
    [[[window0]]]
      type = Window
      parent = ""
    [[[child1]]]
      type = Terminal
      parent = window0
      profile = default
[plugins]
```

<br />

## Grabbing Color Schemes from Windows Terminal

```python
# Convert the WindowsTerminal color scheme format to terminator format

Windows_theme = {
  "name": "Apple Classic",
  "black": "#000000",
  "red": "#c91b00",
  "green": "#00c200",
  "yellow": "#c7c400",
  "blue": "#0225c7",
  "purple": "#ca30c7",
  "cyan": "#00c5c7",
  "white": "#c7c7c7",
  "brightBlack": "#686868",
  "brightRed": "#ff6e67",
  "brightGreen": "#5ffa68",
  "brightYellow": "#fffc67",
  "brightBlue": "#6871ff",
  "brightPurple": "#ff77ff",
  "brightCyan": "#60fdff",
  "brightWhite": "#ffffff",
  "background": "#2c2b2b",
  "foreground": "#d5a200",
  "selectionBackground": "#6b5b02",
  "cursorColor": "#c7c7c7"
}

palette = f"\
{Windows_theme['black']}:\
{Windows_theme['red']}:\
{Windows_theme['green']}:\
{Windows_theme['yellow']}:\
{Windows_theme['blue']}:\
{Windows_theme['purple']}:\
{Windows_theme['cyan']}:\
{Windows_theme['white']}:\
{Windows_theme['brightBlack']}:\
{Windows_theme['brightRed']}:\
{Windows_theme['brightGreen']}:\
{Windows_theme['brightYellow']}:\
{Windows_theme['brightBlue']}:\
{Windows_theme['brightPurple']}:\
{Windows_theme['brightCyan']}:\
{Windows_theme['brightWhite']}\
"

print(f"background_color = \"{Windows_theme['background']}\"")
print(f"foreground_color = \"{Windows_theme['foreground']}\"")
print(f"palette = \"{palette}\"")

```

## Changing "System Fixed Width Font"

This is definitely distro specific, but for Parrot (MATE) this works:
```sh
gsettings set org.gnome.desktop.interface monospace-font-name 'DejaVu Sans Mono 10'
```
