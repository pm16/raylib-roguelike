#include "load_font.hpp"

Font load_font_cp437(std::string font_file, int base_size) {
    Texture2D fontTexture = LoadTexture(font_file.c_str());
    Font cp437Font;
    cp437Font.texture = fontTexture;
    cp437Font.baseSize = base_size; 
    cp437Font.glyphCount = 256; // For CP437 16X16 sheet used.
    cp437Font.recs = (Rectangle*)MemAlloc(cp437Font.glyphCount * sizeof(Rectangle));
    cp437Font.glyphs = (GlyphInfo*)MemAlloc(cp437Font.glyphCount * sizeof(GlyphInfo));
    cp437Font.glyphPadding = 0;

    for (int i = 0; i < cp437Font.glyphCount; i++) {
        cp437Font.glyphs[i].value = convert_to_unicode(i);
        cp437Font.glyphs[i].offsetX = 0;
        cp437Font.glyphs[i].offsetY = 0;
        cp437Font.glyphs[i].advanceX = base_size;
        
        cp437Font.recs[i].x = (i % 16) * base_size;
        cp437Font.recs[i].y = (i / 16) * base_size;
        cp437Font.recs[i].width = base_size;
        cp437Font.recs[i].height = base_size;
    }
    return cp437Font;
} 

int convert_to_unicode(int code) {
    switch (code) {
        case 0: // 
            return 0x0000;
            break;
        case 1: // ☺
            return 0x263A;
            break;
        case 2: // ☻
            return 0x263B;
            break;
        case 3: // ♥
            return 0x2665;
            break;
        case 4: // ♦
            return 0x2666;
            break;
        case 5: // ♣
            return 0x2663;
            break;
        case 6: // ♠
            return 0x2660;
            break;
        case 7: // •
            return 0x2022;
            break;
        case 8: // ◘
            return 0x25D8;
            break;
        case 9: // ○
            return 0x25CB;
            break;
        case 10: // ◙
            return 0x25D9;
            break;
        case 11: // ♂
            return 0x2642;
            break;
        case 12: // ♀
            return 0x2640;
            break;
        case 13: // ♪
            return 0x266A;
            break;
        case 14: // ♫
            return 0x266B;
            break;
        case 15: // ☼
            return 0x263C;
            break;
        case 16: // ►
            return 0x25BA;
            break;
        case 17: // ◄
            return 0x25C4;
            break;
        case 18: // ↕
            return 0x2195;
            break;
        case 19: // ‼
            return 0x203C;
            break;
        case 20: // ¶
            return 0x00B6;
            break;
        case 21: // §
            return 0x00A7;
            break;
        case 22: // ▬
            return 0x25AC;
            break;
        case 23: // ↨
            return 0x21A8;
            break;
        case 24: // ↑
            return 0x2191;
            break;
        case 25: // ↓
            return 0x2193;
            break;
        case 26: // →
            return 0x2192;
            break;
        case 27: // ←
            return 0x2190;
            break;
        case 28: // ∟
            return 0x221F;
            break;
        case 29: // ↔
            return 0x2194;
            break;
        case 30: // ▲
            return 0x25B2;
            break;
        case 31: // ▼
            return 0x25BC;
            break;
        case 32: // (space)
            return 0x0020;
            break;
        case 33: // !
            return 0x0021;
            break;
        case 34: // "
            return 0x0022;
            break;
        case 35: // #
            return 0x0023;
            break;
        case 36: // $
            return 0x0024;
            break;
        case 37: // %
            return 0x0025;
            break;
        case 38: // &
            return 0x0026;
            break;
        case 39: // '
            return 0x0027;
            break;
        case 40: // (
            return 0x0028;
            break;
        case 41: // )
            return 0x0029;
            break;
        case 42: // *
            return 0x002A;
            break;
        case 43: // +
            return 0x002B;
            break;
        case 44: // ,
            return 0x002C;
            break;
        case 45: // -
            return 0x002D;
            break;
        case 46: // .
            return 0x002E;
            break;
        case 47: // /
            return 0x002F;
            break;
        case 48: // 0
            return 0x0030;
            break;
        case 49: // 1
            return 0x0031;
            break;
        case 50: // 2
            return 0x0032;
            break;
        case 51: // 3
            return 0x0033;
            break;
        case 52: // 4
            return 0x0034;
            break;
        case 53: // 5
            return 0x0035;
            break;
        case 54: // 6
            return 0x0036;
            break;
        case 55: // 7
            return 0x0037;
            break;
        case 56: // 8
            return 0x0038;
            break;
        case 57: // 9
            return 0x0039;
            break;
        case 58: // :
            return 0x003A;
            break;
        case 59: // ;
            return 0x003B;
            break;
        case 60: // <
            return 0x003C;
            break;
        case 61: // =
            return 0x003D;
            break;
        case 62: // >
            return 0x003E;
            break;
        case 63: // ?
            return 0x003F;
            break;
        case 64: // @
            return 0x0040;
            break;
        case 65: // A
            return 0x0041;
            break;
        case 66: // B
            return 0x0042;
            break;
        case 67: // C
            return 0x0043;
            break;
        case 68: // D
            return 0x0044;
            break;
        case 69: // E
            return 0x0045;
            break;
        case 70: // F
            return 0x0046;
            break;
        case 71: // G
            return 0x0047;
            break;
        case 72: // H
            return 0x0048;
            break;
        case 73: // I
            return 0x0049;
            break;
        case 74: // J
            return 0x004A;
            break;
        case 75: // K
            return 0x004B;
            break;
        case 76: // L
            return 0x004C;
            break;
        case 77: // M
            return 0x004D;
            break;
        case 78: // N
            return 0x004E;
            break;
        case 79: // O
            return 0x004F;
            break;
        case 80: // P
            return 0x0050;
            break;
        case 81: // Q
            return 0x0051;
            break;
        case 82: // R
            return 0x0052;
            break;
        case 83: // S
            return 0x0053;
            break;
        case 84: // T
            return 0x0054;
            break;
        case 85: // U
            return 0x0055;
            break;
        case 86: // V
            return 0x0056;
            break;
        case 87: // W
            return 0x0057;
            break;
        case 88: // X
            return 0x0058;
            break;
        case 89: // Y
            return 0x0059;
            break;
        case 90: // Z
            return 0x005A;
            break;
        case 91: // [
            return 0x005B;
            break;
        case 92: /* \ */
            return 0x005C;
            break;
        case 93: // ]
            return 0x005D;
            break;
        case 94: // ^
            return 0x005E;
            break;
        case 95: // _
            return 0x005F;
            break;
        case 96: // `
            return 0x0060;
            break;
        case 97: // a
            return 0x0061;
            break;
        case 98: // b
            return 0x0062;
            break;
        case 99: // c
            return 0x0063;
            break;
        case 100: // d
            return 0x0064;
            break;
        case 101: // e
            return 0x0065;
            break;
        case 102: // f
            return 0x0066;
            break;
        case 103: // g
            return 0x0067;
            break;
        case 104: // h
            return 0x0068;
            break;
        case 105: // i
            return 0x0069;
            break;
        case 106: // j
            return 0x006A;
            break;
        case 107: // k
            return 0x006B;
            break;
        case 108: // l
            return 0x006C;
            break;
        case 109: // m
            return 0x006D;
            break;
        case 110: // n
            return 0x006E;
            break;
        case 111: // o
            return 0x006F;
            break;
        case 112: // p
            return 0x0070;
            break;
        case 113: // q
            return 0x0071;
            break;
        case 114: // r
            return 0x0072;
            break;
        case 115: // s
            return 0x0073;
            break;
        case 116: // t
            return 0x0074;
            break;
        case 117: // u
            return 0x0075;
            break;
        case 118: // v
            return 0x0076;
            break;
        case 119: // w
            return 0x0077;
            break;
        case 120: // x
            return 0x0078;
            break;
        case 121: // y
            return 0x0079;
            break;
        case 122: // z
            return 0x007A;
            break;
        case 123: // {
            return 0x007B;
            break;
        case 124: // |
            return 0x007C;
            break;
        case 125: // }
            return 0x007D;
            break;
        case 126: // ~
            return 0x007E;
            break;
        case 127: // ⌂
            return 0x2302;
            break;
        case 128: // Ç
            return 0x00C7;
            break;
        case 129: // ü
            return 0x00FC;
            break;
        case 130: // é
            return 0x00E9;
            break;
        case 131: // â
            return 0x00E2;
            break;
        case 132: // ä
            return 0x00E4;
            break;
        case 133: // à
            return 0x00E0;
            break;
        case 134: // å
            return 0x00E5;
            break;
        case 135: // ç
            return 0x00E7;
            break;
        case 136: // ê
            return 0x00EA;
            break;
        case 137: // ë
            return 0x00EB;
            break;
        case 138: // è
            return 0x00E8;
            break;
        case 139: // ï
            return 0x00EF;
            break;
        case 140: // î
            return 0x00EE;
            break;
        case 141: // ì
            return 0x00EC;
            break;
        case 142: // Ä
            return 0x00C4;
            break;
        case 143: // Å
            return 0x00C5;
            break;
        case 144: // É
            return 0x00C9;
            break;
        case 145: // æ
            return 0x00E6;
            break;
        case 146: // Æ
            return 0x00C6;
            break;
        case 147: // ô
            return 0x00F4;
            break;
        case 148: // ö
            return 0x00F6;
            break;
        case 149: // ò
            return 0x00F2;
            break;
        case 150: // û
            return 0x00FB;
            break;
        case 151: // ù
            return 0x00F9;
            break;
        case 152: // ÿ
            return 0x00FF;
            break;
        case 153: // Ö
            return 0x00D6;
            break;
        case 154: // Ü
            return 0x00DC;
            break;
        case 155: // ¢
            return 0x00A2;
            break;
        case 156: // £
            return 0x00A3;
            break;
        case 157: // ¥
            return 0x00A5;
            break;
        case 158: // ₧
            return 0x20A7;
            break;
        case 159: // ƒ
            return 0x0192;
            break;
        case 160: // á
            return 0x00E1;
            break;
        case 161: // í
            return 0x00ED;
            break;
        case 162: // ó
            return 0x00F3;
            break;
        case 163: // ú
            return 0x00FA;
            break;
        case 164: // ñ
            return 0x00F1;
            break;
        case 165: // Ñ
            return 0x00D1;
            break;
        case 166: // ª
            return 0x00AA;
            break;
        case 167: // º
            return 0x00BA;
            break;
        case 168: // ¿
            return 0x00BF;
            break;
        case 169: // ⌐
            return 0x2310;
            break;
        case 170: // ¬
            return 0x00AC;
            break;
        case 171: // ½
            return 0x00BD;
            break;
        case 172: // ¼
            return 0x00BC;
            break;
        case 173: // ¡
            return 0x00A1;
            break;
        case 174: // «
            return 0x00AB;
            break;
        case 175: // »
            return 0x00BB;
            break;
        case 176: // ░
            return 0x2591;
            break;
        case 177: // ▒
            return 0x2592;
            break;
        case 178: // ▓
            return 0x2593;
            break;
        case 179: // │
            return 0x2502;
            break;
        case 180: // ┤
            return 0x2524;
            break;
        case 181: // ╡
            return 0x2561;
            break;
        case 182: // ╢
            return 0x2562;
            break;
        case 183: // ╖
            return 0x2556;
            break;
        case 184: // ╕
            return 0x2555;
            break;
        case 185: // ╣
            return 0x2563;
            break;
        case 186: // ║
            return 0x2551;
            break;
        case 187: // ╗
            return 0x2557;
            break;
        case 188: // ╝
            return 0x255D;
            break;
        case 189: // ╜
            return 0x255C;
            break;
        case 190: // ╛
            return 0x255B;
            break;
        case 191: // ┐
            return 0x2510;
            break;
        case 192: // └
            return 0x2514;
            break;
        case 193: // ┴
            return 0x2534;
            break;
        case 194: // ┬
            return 0x252C;
            break;
        case 195: // ├
            return 0x251C;
            break;
        case 196: // ─
            return 0x2500;
            break;
        case 197: // ┼
            return 0x253C;
            break;
        case 198: // ╞
            return 0x255E;
            break;
        case 199: // ╟
            return 0x255F;
            break;
        case 200: // ╚
            return 0x255A;
            break;
        case 201: // ╔
            return 0x2554;
            break;
        case 202: // ╩
            return 0x2569;
            break;
        case 203: // ╦
            return 0x2566;
            break;
        case 204: // ╠
            return 0x2560;
            break;
        case 205: // ═
            return 0x2550;
            break;
        case 206: // ╬
            return 0x256C;
            break;
        case 207: // ╧
            return 0x2567;
            break;
        case 208: // ╨
            return 0x2568;
            break;
        case 209: // ╤
            return 0x2564;
            break;
        case 210: // ╥
            return 0x2565;
            break;
        case 211: // ╙
            return 0x2559;
            break;
        case 212: // ╘
            return 0x2558;
            break;
        case 213: // ╒
            return 0x2552;
            break;
        case 214: // ╓
            return 0x2553;
            break;
        case 215: // ╫
            return 0x256B;
            break;
        case 216: // ╪
            return 0x256A;
            break;
        case 217: // ┘
            return 0x2518;
            break;
        case 218: // ┌
            return 0x250C;
            break;
        case 219: // █
            return 0x2588;
            break;
        case 220: // ▄
            return 0x2584;
            break;
        case 221: // ▌
            return 0x258C;
            break;
        case 222: // ▐
            return 0x2590;
            break;
        case 223: // ▀
            return 0x2580;
            break;
        case 224: // α
            return 0x03B1;
            break;
        case 225: // ß
            return 0x00DF;
            break;
        case 226: // Γ
            return 0x0393;
            break;
        case 227: // π
            return 0x03C0;
            break;
        case 228: // Σ
            return 0x03A3;
            break;
        case 229: // σ
            return 0x03C3;
            break;
        case 230: // µ
            return 0x00B5;
            break;
        case 231: // τ
            return 0x03C4;
            break;
        case 232: // Φ
            return 0x03A6;
            break;
        case 233: // Θ
            return 0x0398;
            break;
        case 234: // Ω
            return 0x03A9;
            break;
        case 235: // δ
            return 0x03B4;
            break;
        case 236: // ∞
            return 0x221E;
            break;
        case 237: // φ
            return 0x03C6;
            break;
        case 238: // ε
            return 0x03B5;
            break;
        case 239: // ∩
            return 0x2229;
            break;
        case 240: // ≡
            return 0x2261;
            break;
        case 241: // ±
            return 0x00B1;
            break;
        case 242: // ≥
            return 0x2265;
            break;
        case 243: // ≤
            return 0x2264;
            break;
        case 244: // ⌠
            return 0x2320;
            break;
        case 245: // ⌡
            return 0x2321;
            break;
        case 246: // ÷
            return 0x00F7;
            break;
        case 247: // ≈
            return 0x2248;
            break;
        case 248: // °
            return 0x00B0;
            break;
        case 249: // ∙
            return 0x2219;
            break;
        case 250: // ·
            return 0x00B7;
            break;
        case 251: // √
            return 0x221A;
            break;
        case 252: // ⁿ
            return 0x207F;
            break;
        case 253: // ²
            return 0x00B2;
            break;
        case 254: // ■
            return 0x25A0;
            break;
        case 255: //  
            return 0x00A0;
            break;
        
        default:
            // For any code outside the 0-255 range
            return 0x0000; 
            break;
    }

}