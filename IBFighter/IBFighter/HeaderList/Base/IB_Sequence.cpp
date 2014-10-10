// --------------------------------------------------------
//	IB_Sequencer.cpp
// --------------------------------------------------------
//	IB_Sequencer.hpp �̃����o�֐��̎��̂�u��
// --------------------------------------------------------
#include "IB_BaseInclude.hpp"

// ----------------------------------------------------
//	Sequencer
// ----------------------------------------------------
//	Sequencer::Sequencer (Constructor)
// ----------------------------------------------------
				Sequencer::Sequencer()
{
	this->Sequencer::Sequencer(0);
}

// ----------------------------------------------------
//	Sequencer::Sequencer (Constructor)
// ----------------------------------------------------
				Sequencer::Sequencer(unsigned int Stat)
{
	_Status = Stat;
	_SeqChanged = 0;
}

// ----------------------------------------------------
//	Sequencer::Process
// ----------------------------------------------------
unsigned int	Sequencer::Process()
{
	// ������
	_SeqChanged = 0;
	// ���݊m�F���s�����݂���Ȃ���s
	if(_FuncList.count(_Status) != 0){
		_FuncList[_Status](*this);
	}
	return _SeqChanged;
}

// ----------------------------------------------------
//	Sequencer::RegistFunction
// ----------------------------------------------------
void			Sequencer::RegistFunction(unsigned int Stat, function<void(Sequencer&)> Fc)
{
	// ���݊m�F
	if(_FuncList.count(Stat) != 0){
		// ���݂���ꍇ�l������������
		_FuncList[Stat] = Fc;
	}
	else {
		// ���݂��Ȃ��ꍇ�}������
		_FuncList.insert(
			std::map<unsigned int, function<void(Sequencer&)>>::value_type(Stat, Fc));
	}
	return;
}

// ----------------------------------------------------
//	Sequencer::GetStatus
// ----------------------------------------------------
unsigned		Sequencer::GetStatus() const
{
	return _Status;
}

// ----------------------------------------------------
//	Sequencer::SetStatus
// ----------------------------------------------------
void			Sequencer::SetStatus(unsigned int Stat)
{
	_Status = _SeqChanged = Stat;
}

