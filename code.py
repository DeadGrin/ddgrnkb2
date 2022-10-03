print("Starting")

import board

from kmk.extensions.statusled import statusLED
from kmk.kmk_keyboard import KMKKeyboard
from kmk.keys import KC
from kmk.scanners import DiodeOrientation
from kmk.handlers.sequences import simple_key_sequence
from kmk.modules.layers import Layers
from kmk.keys import KC, make_key
from kmk.modules.combos import Combos, Chord, Sequence
keyboard = KMKKeyboard()
keyboard.modules.append(Layers())
combos = Combos()
keyboard.modules.append(combos)

statusLED = statusLED(led_pins=[board.GP28, board.GP26])
keyboard.extensions.append(statusLED)


ALTSHFT = simple_key_sequence(
(
KC.LALT(KC.LSFT),
KC.TG(1),
)
)

combos.combos = [
    Chord((KC.LALT, KC.LSFT), ALTSHFT)   
]



keyboard.col_pins = (board.GP11, board.GP15, board.GP18, board.GP17, board.GP6,
                     board.GP9, board.GP5, board.GP16, board.GP0, board.GP14,
                     board.GP20, board.GP19, board.GP10, board.GP21, board.GP13,
                     board.GP7, board.GP12, board.GP8,)    # try D5 on Feather, keeboar
keyboard.row_pins = (board.GP3, board.GP4, board.GP22, board.GP1, board.GP2,)    # try D6 on Feather, keeboar
keyboard.diode_orientation = DiodeOrientation.COL2ROW



keyboard.keymap = [
    #colemak
    [ 
KC.PMNS, KC.PAST, KC.PSLS, KC.NLCK, KC.ESC, KC.N1, KC.N2, KC.N3, KC.N4, KC.N5, KC.N6, KC.N7, KC.N8, KC.N9, KC.N0, KC.MINS, KC.EQL, KC.PSCR, 
KC.PPLS,KC.P7, KC.P8, KC.P9, KC.TAB, KC.Q, KC.W, KC.F, KC.P, KC.G, KC.J, KC.L, KC.U, KC.Y, KC.SCLN, KC.LBRC, KC.RBRC, KC.GRV, 
KC.PPLS, KC.P4, KC.P5, KC.P6, KC.CAPS, KC.A, KC.R, KC.S, KC.T, KC.D, KC.H, KC.N, KC.E, KC.I, KC.O, KC.QUOT, KC.ENT, KC.ENT, 
KC.PENT,KC.P1, KC.P2, KC.P3, KC.LSFT, KC.Z, KC.X, KC.C, KC.V, KC.B, KC.K, KC.M, KC.COMM, KC.DOT, KC.SLSH, KC.BSLS, KC.UP, KC.LSFT, 
KC.PENT, KC.P0, KC.P0, KC.PDOT, KC.LCTL, KC.LGUI, KC.LALT, KC.TG(1), KC.BSPC, KC.SPC, KC.SPC, KC.DEL, KC.TG(2), KC.RALT, KC.RCTL, KC.LEFT, KC.DOWN, KC.RGHT,
],
#qwerty
[
KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, 
KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.Q, KC.W, KC.E, KC.R, KC.T, KC.Y, KC.U, KC.I, KC.O, KC.P, KC.LBRC, KC.RBRC, KC.TRNS, 
KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.A, KC.S, KC.D, KC.F, KC.G, KC.H, KC.J, KC.K, KC.L, KC.SCLN, KC.TRNS, KC.TRNS, KC.TRNS, 
KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.Z, KC.X, KC.C, KC.V, KC.B, KC.N, KC.M, KC.COMM, KC.DOT, KC.SLSH, KC.BSLS, KC.TRNS, KC.TRNS, 
KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS,
    ],
#F
[
KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.F1, KC.F2, KC.F3, KC.F4, KC.F5, KC.F6, KC.F7, KC.F8, KC.F9, KC.F10, KC.F11, KC.F12, KC.TRNS, 
KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, 
KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, 
KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, 
KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, KC.TRNS, 
    ],
]
if __name__ == '__main__':
    keyboard.go()