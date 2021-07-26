// File: Asm_x86_64_Jitdb.cpp
// Author: Mario
// Created: 07.27.2021 5:38 PM
// Project: NominaxRuntime
// 
//                                  Apache License
//                            Version 2.0, January 2004
//                         http://www.apache.org/licenses/
// 
//    TERMS AND CONDITIONS FOR USE, REPRODUCTION, AND DISTRIBUTION
// 
//    1. Definitions.
// 
//       "License" shall mean the terms and conditions for use, reproduction,
//       and distribution as defined by Sections 1 through 9 of this document.
// 
//       "Licensor" shall mean the copyright owner or entity authorized by
//       the copyright owner that is granting the License.
// 
//       "Legal Entity" shall mean the union of the acting entity and all
//       other entities that control, are controlled by, or are under common
//       control with that entity. For the purposes of this definition,
//       "control" means (i) the power, direct or indirect, to cause the
//       direction or management of such entity, whether by contract or
//       otherwise, or (ii) ownership of fifty percent (50%) or more of the
//       outstanding shares, or (iii) beneficial ownership of such entity.
// 
//       "You" (or "Your") shall mean an individual or Legal Entity
//       exercising permissions granted by this License.
// 
//       "Source" form shall mean the preferred form for making modifications,
//       including but not limited to software source code, documentation
//       source, and configuration files.
// 
//       "Object" form shall mean any form resulting from mechanical
//       transformation or translation of a Source form, including but
//       not limited to compiled object code, generated documentation,
//       and conversions to other media types.
// 
//       "Work" shall mean the work of authorship, whether in Source or
//       Object form, made available under the License, as indicated by a
//       copyright notice that is included in or attached to the work
//       (an example is provided in the Appendix below).
// 
//       "Derivative Works" shall mean any work, whether in Source or Object
//       form, that is based on (or derived from) the Work and for which the
//       editorial revisions, annotations, elaborations, or other modifications
//       represent, as a whole, an original work of authorship. For the purposes
//       of this License, Derivative Works shall not include works that remain
//       separable from, or merely link (or bind by name) to the interfaces of,
//       the Work and Derivative Works thereof.
// 
//       "Contribution" shall mean any work of authorship, including
//       the original version of the Work and any modifications or additions
//       to that Work or Derivative Works thereof, that is intentionally
//       submitted to Licensor for inclusion in the Work by the copyright owner
//       or by an individual or Legal Entity authorized to submit on behalf of
//       the copyright owner. For the purposes of this definition, "submitted"
//       means any form of electronic, verbal, or written communication sent
//       to the Licensor or its representatives, including but not limited to
//       communication on electronic mailing lists, source code control systems,
//       and issue tracking systems that are managed by, or on behalf of, the
//       Licensor for the purpose of discussing and improving the Work, but
//       excluding communication that is conspicuously marked or otherwise
//       designated in writing by the copyright owner as "Not a Contribution."
// 
//       "Contributor" shall mean Licensor and any individual or Legal Entity
//       on behalf of whom a Contribution has been received by Licensor and
//       subsequently incorporated within the Work.
// 
//    2. Grant of Copyright License. Subject to the terms and conditions of
//       this License, each Contributor hereby grants to You a perpetual,
//       worldwide, non-exclusive, no-charge, royalty-free, irrevocable
//       copyright license to reproduce, prepare Derivative Works of,
//       publicly display, publicly perform, sublicense, and distribute the
//       Work and such Derivative Works in Source or Object form.
// 
//    3. Grant of Patent License. Subject to the terms and conditions of
//       this License, each Contributor hereby grants to You a perpetual,
//       worldwide, non-exclusive, no-charge, royalty-free, irrevocable
//       (except as stated in this section) patent license to make, have made,
//       use, offer to sell, sell, import, and otherwise transfer the Work,
//       where such license applies only to those patent claims licensable
//       by such Contributor that are necessarily infringed by their
//       Contribution(s) alone or by combination of their Contribution(s)
//       with the Work to which such Contribution(s) was submitted. If You
//       institute patent litigation against any entity (including a
//       cross-claim or counterclaim in a lawsuit) alleging that the Work
//       or a Contribution incorporated within the Work constitutes direct
//       or contributory patent infringement, then any patent licenses
//       granted to You under this License for that Work shall terminate
//       as of the date such litigation is filed.
// 
//    4. Redistribution. You may reproduce and distribute copies of the
//       Work or Derivative Works thereof in any medium, with or without
//       modifications, and in Source or Object form, provided that You
//       meet the following conditions:
// 
//       (a) You must give any other recipients of the Work or
//           Derivative Works a copy of this License; and
// 
//       (b) You must cause any modified files to carry prominent notices
//           stating that You changed the files; and
// 
//       (c) You must retain, in the Source form of any Derivative Works
//           that You distribute, all copyright, patent, trademark, and
//           attribution notices from the Source form of the Work,
//           excluding those notices that do not pertain to any part of
//           the Derivative Works; and
// 
//       (d) If the Work includes a "NOTICE" text file as part of its
//           distribution, then any Derivative Works that You distribute must
//           include a readable copy of the attribution notices contained
//           within such NOTICE file, excluding those notices that do not
//           pertain to any part of the Derivative Works, in at least one
//           of the following places: within a NOTICE text file distributed
//           as part of the Derivative Works; within the Source form or
//           documentation, if provided along with the Derivative Works; or,
//           within a display generated by the Derivative Works, if and
//           wherever such third-party notices normally appear. The contents
//           of the NOTICE file are for informational purposes only and
//           do not modify the License. You may add Your own attribution
//           notices within Derivative Works that You distribute, alongside
//           or as an addendum to the NOTICE text from the Work, provided
//           that such additional attribution notices cannot be construed
//           as modifying the License.
// 
//       You may add Your own copyright statement to Your modifications and
//       may provide additional or different license terms and conditions
//       for use, reproduction, or distribution of Your modifications, or
//       for any such Derivative Works as a whole, provided Your use,
//       reproduction, and distribution of the Work otherwise complies with
//       the conditions stated in this License.
// 
//    5. Submission of Contributions. Unless You explicitly state otherwise,
//       any Contribution intentionally submitted for inclusion in the Work
//       by You to the Licensor shall be under the terms and conditions of
//       this License, without any additional terms or conditions.
//       Notwithstanding the above, nothing herein shall supersede or modify
//       the terms of any separate license agreement you may have executed
//       with Licensor regarding such Contributions.
// 
//    6. Trademarks. This License does not grant permission to use the trade
//       names, trademarks, service marks, or product names of the Licensor,
//       except as required for reasonable and customary use in describing the
//       origin of the Work and reproducing the content of the NOTICE file.
// 
//    7. Disclaimer of Warranty. Unless required by applicable law or
//       agreed to in writing, Licensor provides the Work (and each
//       Contributor provides its Contributions) on an "AS IS" BASIS,
//       WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
//       implied, including, without limitation, any warranties or conditions
//       of TITLE, NON-INFRINGEMENT, MERCHANTABILITY, or FITNESS FOR A
//       PARTICULAR PURPOSE. You are solely responsible for determining the
//       appropriateness of using or redistributing the Work and assume any
//       risks associated with Your exercise of permissions under this License.
// 
//    8. Limitation of Liability. In no event and under no legal theory,
//       whether in tort (including negligence), contract, or otherwise,
//       unless required by applicable law (such as deliberate and grossly
//       negligent acts) or agreed to in writing, shall any Contributor be
//       liable to You for damages, including any direct, indirect, special,
//       incidental, or consequential damages of any character arising as a
//       result of this License or out of the use or inability to use the
//       Work (including but not limited to damages for loss of goodwill,
//       work stoppage, computer failure or malfunction, or any and all
//       other commercial damages or losses), even if such Contributor
//       has been advised of the possibility of such damages.
// 
//    9. Accepting Warranty or Additional Liability. While redistributing
//       the Work or Derivative Works thereof, You may choose to offer,
//       and charge a fee for, acceptance of support, warranty, indemnity,
//       or other liability obligations and/or rights consistent with this
//       License. However, in accepting such obligations, You may act only
//       on Your own behalf and on Your sole responsibility, not on behalf
//       of any other Contributor, and only if You agree to indemnify,
//       defend, and hold each Contributor harmless for any liability
//       incurred by, or claims asserted against, such Contributor by reason
//       of your accepting any such warranty or additional liability.
// 
//    END OF TERMS AND CONDITIONS
// 
//    APPENDIX: How to apply the Apache License to your work.
// 
//       To apply the Apache License to your work, attach the following
//       boilerplate notice, with the fields enclosed by brackets "[]"
//       replaced with your own identifying information. (Don't include
//       the brackets!)  The text should be enclosed in the appropriate
//       comment syntax for the file format. We also recommend that a
//       file or class name and description of purpose be included on the
//       same "printed page" as the copyright notice for easier
//       identification within third-party archives.
// 
//    Copyright 2021 Mario Sieg "pinsrq" <mt3000@gmx.de>
// 
//    Licensed under the Apache License, Version 2.0 (the "License");
//    you may not use this file except in compliance with the License.
//    You may obtain a copy of the License at
// 
//        http://www.apache.org/licenses/LICENSE-2.0
// 
//    Unless required by applicable law or agreed to in writing, software
//    distributed under the License is distributed on an "AS IS" BASIS,
//    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//    See the License for the specific language governing permissions and
//    limitations under the License.

// Auto generated, do not edit!

#include "../Include/Nominax/Asm_x86_64.hpp"

namespace Nominax::Assembler::X86_64
{
NOX_NEVER_INLINE NOX_COLD auto GetVariationTable_15(std::pmr::monotonic_buffer_resource& allocator, std::pmr::vector<InstructionVariationPool>& out) -> void
{
	std::pmr::vector<InstructionVariation> instruction{&allocator};
	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "setae",
			.GasMnemonic = "setae",
			.Description = "setae r8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x93,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "setae",
			.GasMnemonic = "setae",
			.Description = "setae m8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {OperandType::M8},
						.B = {OperandType::M8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x93,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M8},
						.Rm = {OperandType::M8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "setb",
			.GasMnemonic = "setb",
			.Description = "setb r8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x92,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "setb",
			.GasMnemonic = "setb",
			.Description = "setb m8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {OperandType::M8},
						.B = {OperandType::M8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x92,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M8},
						.Rm = {OperandType::M8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "setbe",
			.GasMnemonic = "setbe",
			.Description = "setbe r8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x96,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "setbe",
			.GasMnemonic = "setbe",
			.Description = "setbe m8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {OperandType::M8},
						.B = {OperandType::M8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x96,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M8},
						.Rm = {OperandType::M8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "setc",
			.GasMnemonic = "setc",
			.Description = "setc r8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x92,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "setc",
			.GasMnemonic = "setc",
			.Description = "setc m8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {OperandType::M8},
						.B = {OperandType::M8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x92,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M8},
						.Rm = {OperandType::M8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "sete",
			.GasMnemonic = "sete",
			.Description = "sete r8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x94,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "sete",
			.GasMnemonic = "sete",
			.Description = "sete m8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {OperandType::M8},
						.B = {OperandType::M8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x94,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M8},
						.Rm = {OperandType::M8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "setg",
			.GasMnemonic = "setg",
			.Description = "setg r8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x9f,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "setg",
			.GasMnemonic = "setg",
			.Description = "setg m8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {OperandType::M8},
						.B = {OperandType::M8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x9f,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M8},
						.Rm = {OperandType::M8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "setge",
			.GasMnemonic = "setge",
			.Description = "setge r8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x9d,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "setge",
			.GasMnemonic = "setge",
			.Description = "setge m8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {OperandType::M8},
						.B = {OperandType::M8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x9d,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M8},
						.Rm = {OperandType::M8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "setl",
			.GasMnemonic = "setl",
			.Description = "setl r8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x9c,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "setl",
			.GasMnemonic = "setl",
			.Description = "setl m8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {OperandType::M8},
						.B = {OperandType::M8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x9c,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M8},
						.Rm = {OperandType::M8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "setle",
			.GasMnemonic = "setle",
			.Description = "setle r8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x9e,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "setle",
			.GasMnemonic = "setle",
			.Description = "setle m8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {OperandType::M8},
						.B = {OperandType::M8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x9e,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M8},
						.Rm = {OperandType::M8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "setna",
			.GasMnemonic = "setna",
			.Description = "setna r8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x96,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "setna",
			.GasMnemonic = "setna",
			.Description = "setna m8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {OperandType::M8},
						.B = {OperandType::M8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x96,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M8},
						.Rm = {OperandType::M8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "setnae",
			.GasMnemonic = "setnae",
			.Description = "setnae r8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x92,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "setnae",
			.GasMnemonic = "setnae",
			.Description = "setnae m8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {OperandType::M8},
						.B = {OperandType::M8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x92,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M8},
						.Rm = {OperandType::M8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "setnb",
			.GasMnemonic = "setnb",
			.Description = "setnb r8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x93,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "setnb",
			.GasMnemonic = "setnb",
			.Description = "setnb m8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {OperandType::M8},
						.B = {OperandType::M8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x93,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M8},
						.Rm = {OperandType::M8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "setnbe",
			.GasMnemonic = "setnbe",
			.Description = "setnbe r8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x97,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "setnbe",
			.GasMnemonic = "setnbe",
			.Description = "setnbe m8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {OperandType::M8},
						.B = {OperandType::M8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x97,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M8},
						.Rm = {OperandType::M8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "setnc",
			.GasMnemonic = "setnc",
			.Description = "setnc r8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x93,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "setnc",
			.GasMnemonic = "setnc",
			.Description = "setnc m8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {OperandType::M8},
						.B = {OperandType::M8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x93,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M8},
						.Rm = {OperandType::M8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "setne",
			.GasMnemonic = "setne",
			.Description = "setne r8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x95,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "setne",
			.GasMnemonic = "setne",
			.Description = "setne m8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {OperandType::M8},
						.B = {OperandType::M8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x95,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M8},
						.Rm = {OperandType::M8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "setng",
			.GasMnemonic = "setng",
			.Description = "setng r8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x9e,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "setng",
			.GasMnemonic = "setng",
			.Description = "setng m8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {OperandType::M8},
						.B = {OperandType::M8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x9e,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M8},
						.Rm = {OperandType::M8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "setnge",
			.GasMnemonic = "setnge",
			.Description = "setnge r8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x9c,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "setnge",
			.GasMnemonic = "setnge",
			.Description = "setnge m8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {OperandType::M8},
						.B = {OperandType::M8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x9c,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M8},
						.Rm = {OperandType::M8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "setnl",
			.GasMnemonic = "setnl",
			.Description = "setnl r8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x9d,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "setnl",
			.GasMnemonic = "setnl",
			.Description = "setnl m8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {OperandType::M8},
						.B = {OperandType::M8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x9d,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M8},
						.Rm = {OperandType::M8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "setnle",
			.GasMnemonic = "setnle",
			.Description = "setnle r8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x9f,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "setnle",
			.GasMnemonic = "setnle",
			.Description = "setnle m8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {OperandType::M8},
						.B = {OperandType::M8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x9f,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M8},
						.Rm = {OperandType::M8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "setno",
			.GasMnemonic = "setno",
			.Description = "setno r8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x91,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "setno",
			.GasMnemonic = "setno",
			.Description = "setno m8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {OperandType::M8},
						.B = {OperandType::M8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x91,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M8},
						.Rm = {OperandType::M8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "setnp",
			.GasMnemonic = "setnp",
			.Description = "setnp r8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x9b,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "setnp",
			.GasMnemonic = "setnp",
			.Description = "setnp m8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {OperandType::M8},
						.B = {OperandType::M8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x9b,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M8},
						.Rm = {OperandType::M8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "setns",
			.GasMnemonic = "setns",
			.Description = "setns r8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x99,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "setns",
			.GasMnemonic = "setns",
			.Description = "setns m8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {OperandType::M8},
						.B = {OperandType::M8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x99,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M8},
						.Rm = {OperandType::M8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "setnz",
			.GasMnemonic = "setnz",
			.Description = "setnz r8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x95,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "setnz",
			.GasMnemonic = "setnz",
			.Description = "setnz m8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {OperandType::M8},
						.B = {OperandType::M8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x95,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M8},
						.Rm = {OperandType::M8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "seto",
			.GasMnemonic = "seto",
			.Description = "seto r8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x90,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "seto",
			.GasMnemonic = "seto",
			.Description = "seto m8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {OperandType::M8},
						.B = {OperandType::M8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x90,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M8},
						.Rm = {OperandType::M8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "setp",
			.GasMnemonic = "setp",
			.Description = "setp r8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x9a,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "setp",
			.GasMnemonic = "setp",
			.Description = "setp m8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {OperandType::M8},
						.B = {OperandType::M8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x9a,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M8},
						.Rm = {OperandType::M8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "setpe",
			.GasMnemonic = "setpe",
			.Description = "setpe r8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x9a,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "setpe",
			.GasMnemonic = "setpe",
			.Description = "setpe m8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {OperandType::M8},
						.B = {OperandType::M8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x9a,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M8},
						.Rm = {OperandType::M8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "setpo",
			.GasMnemonic = "setpo",
			.Description = "setpo r8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x9b,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "setpo",
			.GasMnemonic = "setpo",
			.Description = "setpo m8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {OperandType::M8},
						.B = {OperandType::M8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x9b,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M8},
						.Rm = {OperandType::M8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "sets",
			.GasMnemonic = "sets",
			.Description = "sets r8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x98,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "sets",
			.GasMnemonic = "sets",
			.Description = "sets m8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {OperandType::M8},
						.B = {OperandType::M8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x98,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M8},
						.Rm = {OperandType::M8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "setz",
			.GasMnemonic = "setz",
			.Description = "setz r8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::R8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::R8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x94,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::R8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "setz",
			.GasMnemonic = "setz",
			.Description = "setz m8",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::M8,
					.IsInput = false,
					.IsOutput = true,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {UINT64_C(0x0)},
						.X = {OperandType::M8},
						.B = {OperandType::M8},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x94,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M8},
						.Rm = {OperandType::M8},
						.Reg = {UINT64_C(0x0)},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "sfence",
			.GasMnemonic = "sfence",
			.Description = "sfence",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::None,
			.IsCancellingInputs = false,
			.OperandList =
			{
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::MmxExt,
			},
			.EncodingScheme =
			{
				Encoding
				{
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xae,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xf8,
						.Addend = {UINT64_C(0x0)},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "sha1msg1",
			.GasMnemonic = "sha1msg1",
			.Description = "sha1msg1 xmm, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sha,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x38,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xc9,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "sha1msg1",
			.GasMnemonic = "sha1msg1",
			.Description = "sha1msg1 xmm, m128",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M128,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sha,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x38,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xc9,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

	instruction = 
	{
		InstructionVariation
		{
			.IntelMnemonic = "sha1msg2",
			.GasMnemonic = "sha1msg2",
			.Description = "sha1msg2 xmm, xmm",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sha,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {UINT64_C(0x0)},
						.B = {OperandType::Xmm},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x38,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xca,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {UINT64_C(0x3)},
						.Rm = {OperandType::Xmm},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
		InstructionVariation
		{
			.IntelMnemonic = "sha1msg2",
			.GasMnemonic = "sha1msg2",
			.Description = "sha1msg2 xmm, m128",
			.MmxMode = MmxModeType::None,
			.XmmMode = XmmModeType::Sse,
			.IsCancellingInputs = false,
			.OperandList =
			{
				Operand
				{
					.Type = OperandType::Xmm,
					.IsInput = true,
					.IsOutput = true,
					.ExtendedSize = 0
				},
				Operand
				{
					.Type = OperandType::M128,
					.IsInput = true,
					.IsOutput = false,
					.ExtendedSize = 0
				},
			},
			.ImplicitInputs =
			{
			},
			.ImplicitOutputs =
			{
			},
			.IsaFeatureExtensions =
			{
				IsaExtension::Sha,
			},
			.EncodingScheme =
			{
				Encoding
				{
					Rex
					{
						.W = false,
						.R = {OperandType::Xmm},
						.X = {OperandType::M128},
						.B = {OperandType::M128},
						.IsMandatory = false,
					},
					OpCode
					{
						.Value = 0xf,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0x38,
						.Addend = {UINT64_C(0x0)},
					},
					OpCode
					{
						.Value = 0xca,
						.Addend = {UINT64_C(0x0)},
					},
					ModRm
					{
						.Mode = {OperandType::M128},
						.Rm = {OperandType::M128},
						.Reg = {OperandType::Xmm},
					},
				},
			}
		},
	};
	out.emplace_back(std::move(instruction));

};
}
