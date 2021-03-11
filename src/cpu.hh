#ifndef GBC_CPU_H
#define GBC_CPU_H

#include "opcode.hh"
#include "register.hh"

namespace gbc {

class Mmu;

class Cpu {
public:
  Cpu(Mmu &mmu);

private:
  byte_t next_byte();
  word_t next_word();

  // inlined "microcode" functions
  void nop() const;

  template <typename T>
  void ld(WriteableValue<T> &dest, const ReadableValue<T> &src);

  void ld(ByteRegister &reg, const word_t addr);

  void ld(const word_t addr);
  void ld(const word_t addr, ByteRegister &reg);
  void ld(const word_t addr, WordRegister &reg);

  void ldi(const word_t addr, ByteRegister &reg);
  void ldi(ByteRegister &reg, const word_t addr);
  void ldd(const word_t addr, ByteRegister &reg);
  void ldd(ByteRegister &reg, const word_t addr);

  void inc(ByteRegister &reg);
  void inc(WordRegister &reg);
  void inc(const word_t addr);

  void dec(ByteRegister &reg);
  void dec(WordRegister &reg);
  void dec(const word_t addr);

  void rlc(ByteRegister &reg);
  void rlc(const byte_t addr);
  void rl(ByteRegister &reg);
  void rl(const byte_t addr);

  void rrc(ByteRegister &reg);
  void rrc(const byte_t addr);
  void rr(ByteRegister &reg);
  void rr(const byte_t addr);

  void add(ByteRegister &reg, const ByteRegister &other);
  void add(ByteRegister &reg, const word_t addr);
  void add(ByteRegister &reg);
  void add(WordRegister &reg, const WordRegister &other);
  void adc(ByteRegister &reg, const ByteRegister &other);
  void adc(ByteRegister &reg, const word_t addr);
  void adc(ByteRegister &reg);

  void sub(ByteRegister &reg, const ByteRegister &other);
  void sub(ByteRegister &reg, const word_t addr);
  void sub(ByteRegister &reg);
  void sbc(ByteRegister &reg, const ByteRegister &other);
  void sbc(ByteRegister &reg, const word_t addr);
  void sbc(ByteRegister &reg);

  void stop();
  void halt();

  void jr();
  void jr_if(bool condition);

  void a_and(const ByteRegister &other);
  void a_and(const word_t addr);
  void a_and();
  void a_or(const ByteRegister &other);
  void a_or(const word_t addr);
  void a_or();
  void a_xor(const ByteRegister &other);
  void a_xor(const word_t addr);
  void a_xor();

  void sla(ByteRegister &reg);
  void sla(const word_t addr);
  void sra(ByteRegister &reg);
  void sra(const word_t addr);
  void srl(ByteRegister &reg);
  void srl(const word_t addr);

  void swap(ByteRegister &reg);
  void swap(const word_t addr);

  void bit(const byte_t bit, const ByteRegister &reg);
  void bit(const byte_t bit, const word_t addr);

  ByteRegister a, b, c, d, e, h, l;
  ByteRegisterPair af, bc, de, hl;
  WordValuedRegister pc;
  WordValuedRegister sp;
  FlagRegister f;

  Mmu &mmu_;

  bool stopped_ = false;
  bool halted_ = false;
  bool did_branch_ = false;

  /* clang-format off */
  void op_00(); void op_01(); void op_02(); void op_03(); void op_04(); void op_05(); void op_06(); void op_07(); void op_08(); void op_09(); void op_0a(); void op_0b(); void op_0c(); void op_0d(); void op_0e(); void op_0f();
  void op_10(); void op_11(); void op_12(); void op_13(); void op_14(); void op_15(); void op_16(); void op_17(); void op_18(); void op_19(); void op_1a(); void op_1b(); void op_1c(); void op_1d(); void op_1e(); void op_1f();
  void op_20(); void op_21(); void op_22(); void op_23(); void op_24(); void op_25(); void op_26(); void op_27(); void op_28(); void op_29(); void op_2a(); void op_2b(); void op_2c(); void op_2d(); void op_2e(); void op_2f();
  void op_30(); void op_31(); void op_32(); void op_33(); void op_34(); void op_35(); void op_36(); void op_37(); void op_38(); void op_39(); void op_3a(); void op_3b(); void op_3c(); void op_3d(); void op_3e(); void op_3f();
  void op_40(); void op_41(); void op_42(); void op_43(); void op_44(); void op_45(); void op_46(); void op_47(); void op_48(); void op_49(); void op_4a(); void op_4b(); void op_4c(); void op_4d(); void op_4e(); void op_4f();
  void op_50(); void op_51(); void op_52(); void op_53(); void op_54(); void op_55(); void op_56(); void op_57(); void op_58(); void op_59(); void op_5a(); void op_5b(); void op_5c(); void op_5d(); void op_5e(); void op_5f();
  void op_60(); void op_61(); void op_62(); void op_63(); void op_64(); void op_65(); void op_66(); void op_67(); void op_68(); void op_69(); void op_6a(); void op_6b(); void op_6c(); void op_6d(); void op_6e(); void op_6f();
  void op_70(); void op_71(); void op_72(); void op_73(); void op_74(); void op_75(); void op_76(); void op_77(); void op_78(); void op_79(); void op_7a(); void op_7b(); void op_7c(); void op_7d(); void op_7e(); void op_7f();
  void op_80(); void op_81(); void op_82(); void op_83(); void op_84(); void op_85(); void op_86(); void op_87(); void op_88(); void op_89(); void op_8a(); void op_8b(); void op_8c(); void op_8d(); void op_8e(); void op_8f();
  void op_90(); void op_91(); void op_92(); void op_93(); void op_94(); void op_95(); void op_96(); void op_97(); void op_98(); void op_99(); void op_9a(); void op_9b(); void op_9c(); void op_9d(); void op_9e(); void op_9f();
  void op_a0(); void op_a1(); void op_a2(); void op_a3(); void op_a4(); void op_a5(); void op_a6(); void op_a7(); void op_a8(); void op_a9(); void op_aa(); void op_ab(); void op_ac(); void op_ad(); void op_ae(); void op_af();
  void op_b0(); void op_b1(); void op_b2(); void op_b3(); void op_b4(); void op_b5(); void op_b6(); void op_b7(); void op_b8(); void op_b9(); void op_ba(); void op_bb(); void op_bc(); void op_bd(); void op_be(); void op_bf();
  void op_c0(); void op_c1(); void op_c2(); void op_c3(); void op_c4(); void op_c5(); void op_c6(); void op_c7(); void op_c8(); void op_c9(); void op_ca(); void op_cb(); void op_cc(); void op_cd(); void op_ce(); void op_cf();
  void op_d0(); void op_d1(); void op_d2(); void op_d3(); void op_d4(); void op_d5(); void op_d6(); void op_d7(); void op_d8(); void op_d9(); void op_da(); void op_db(); void op_dc(); void op_dd(); void op_de(); void op_df();
  void op_e0(); void op_e1(); void op_e2(); void op_e3(); void op_e4(); void op_e5(); void op_e6(); void op_e7(); void op_e8(); void op_e9(); void op_ea(); void op_eb(); void op_ec(); void op_ed(); void op_ee(); void op_ef();
  void op_f0(); void op_f1(); void op_f2(); void op_f3(); void op_f4(); void op_f5(); void op_f6(); void op_f7(); void op_f8(); void op_f9(); void op_fa(); void op_fb(); void op_fc(); void op_fd(); void op_fe(); void op_ff();

  void op_cb_00(); void op_cb_01(); void op_cb_02(); void op_cb_03(); void op_cb_04(); void op_cb_05(); void op_cb_06(); void op_cb_07(); void op_cb_08(); void op_cb_09(); void op_cb_0a(); void op_cb_0b(); void op_cb_0c(); void op_cb_0d(); void op_cb_0e(); void op_cb_0f();
  void op_cb_10(); void op_cb_11(); void op_cb_12(); void op_cb_13(); void op_cb_14(); void op_cb_15(); void op_cb_16(); void op_cb_17(); void op_cb_18(); void op_cb_19(); void op_cb_1a(); void op_cb_1b(); void op_cb_1c(); void op_cb_1d(); void op_cb_1e(); void op_cb_1f();
  void op_cb_20(); void op_cb_21(); void op_cb_22(); void op_cb_23(); void op_cb_24(); void op_cb_25(); void op_cb_26(); void op_cb_27(); void op_cb_28(); void op_cb_29(); void op_cb_2a(); void op_cb_2b(); void op_cb_2c(); void op_cb_2d(); void op_cb_2e(); void op_cb_2f();
  void op_cb_30(); void op_cb_31(); void op_cb_32(); void op_cb_33(); void op_cb_34(); void op_cb_35(); void op_cb_36(); void op_cb_37(); void op_cb_38(); void op_cb_39(); void op_cb_3a(); void op_cb_3b(); void op_cb_3c(); void op_cb_3d(); void op_cb_3e(); void op_cb_3f();
  void op_cb_40(); void op_cb_41(); void op_cb_42(); void op_cb_43(); void op_cb_44(); void op_cb_45(); void op_cb_46(); void op_cb_47(); void op_cb_48(); void op_cb_49(); void op_cb_4a(); void op_cb_4b(); void op_cb_4c(); void op_cb_4d(); void op_cb_4e(); void op_cb_4f();
  void op_cb_50(); void op_cb_51(); void op_cb_52(); void op_cb_53(); void op_cb_54(); void op_cb_55(); void op_cb_56(); void op_cb_57(); void op_cb_58(); void op_cb_59(); void op_cb_5a(); void op_cb_5b(); void op_cb_5c(); void op_cb_5d(); void op_cb_5e(); void op_cb_5f();
  void op_cb_60(); void op_cb_61(); void op_cb_62(); void op_cb_63(); void op_cb_64(); void op_cb_65(); void op_cb_66(); void op_cb_67(); void op_cb_68(); void op_cb_69(); void op_cb_6a(); void op_cb_6b(); void op_cb_6c(); void op_cb_6d(); void op_cb_6e(); void op_cb_6f();
  void op_cb_70(); void op_cb_71(); void op_cb_72(); void op_cb_73(); void op_cb_74(); void op_cb_75(); void op_cb_76(); void op_cb_77(); void op_cb_78(); void op_cb_79(); void op_cb_7a(); void op_cb_7b(); void op_cb_7c(); void op_cb_7d(); void op_cb_7e(); void op_cb_7f();
  void op_cb_80(); void op_cb_81(); void op_cb_82(); void op_cb_83(); void op_cb_84(); void op_cb_85(); void op_cb_86(); void op_cb_87(); void op_cb_88(); void op_cb_89(); void op_cb_8a(); void op_cb_8b(); void op_cb_8c(); void op_cb_8d(); void op_cb_8e(); void op_cb_8f();
  void op_cb_90(); void op_cb_91(); void op_cb_92(); void op_cb_93(); void op_cb_94(); void op_cb_95(); void op_cb_96(); void op_cb_97(); void op_cb_98(); void op_cb_99(); void op_cb_9a(); void op_cb_9b(); void op_cb_9c(); void op_cb_9d(); void op_cb_9e(); void op_cb_9f();
  void op_cb_a0(); void op_cb_a1(); void op_cb_a2(); void op_cb_a3(); void op_cb_a4(); void op_cb_a5(); void op_cb_a6(); void op_cb_a7(); void op_cb_a8(); void op_cb_a9(); void op_cb_aa(); void op_cb_ab(); void op_cb_ac(); void op_cb_ad(); void op_cb_ae(); void op_cb_af();
  void op_cb_b0(); void op_cb_b1(); void op_cb_b2(); void op_cb_b3(); void op_cb_b4(); void op_cb_b5(); void op_cb_b6(); void op_cb_b7(); void op_cb_b8(); void op_cb_b9(); void op_cb_ba(); void op_cb_bb(); void op_cb_bc(); void op_cb_bd(); void op_cb_be(); void op_cb_bf();
  void op_cb_c0(); void op_cb_c1(); void op_cb_c2(); void op_cb_c3(); void op_cb_c4(); void op_cb_c5(); void op_cb_c6(); void op_cb_c7(); void op_cb_c8(); void op_cb_c9(); void op_cb_ca(); void op_cb_cb(); void op_cb_cc(); void op_cb_cd(); void op_cb_ce(); void op_cb_cf();
  void op_cb_d0(); void op_cb_d1(); void op_cb_d2(); void op_cb_d3(); void op_cb_d4(); void op_cb_d5(); void op_cb_d6(); void op_cb_d7(); void op_cb_d8(); void op_cb_d9(); void op_cb_da(); void op_cb_db(); void op_cb_dc(); void op_cb_dd(); void op_cb_de(); void op_cb_df();
  void op_cb_e0(); void op_cb_e1(); void op_cb_e2(); void op_cb_e3(); void op_cb_e4(); void op_cb_e5(); void op_cb_e6(); void op_cb_e7(); void op_cb_e8(); void op_cb_e9(); void op_cb_ea(); void op_cb_eb(); void op_cb_ec(); void op_cb_ed(); void op_cb_ee(); void op_cb_ef();
  void op_cb_f0(); void op_cb_f1(); void op_cb_f2(); void op_cb_f3(); void op_cb_f4(); void op_cb_f5(); void op_cb_f6(); void op_cb_f7(); void op_cb_f8(); void op_cb_f9(); void op_cb_fa(); void op_cb_fb(); void op_cb_fc(); void op_cb_fd(); void op_cb_fe(); void op_cb_ff();
  /* clang-format on */
};

} // namespace gbc
#endif
